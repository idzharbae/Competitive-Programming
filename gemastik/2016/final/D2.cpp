#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int getSumUtil(int *st, int treeStart, int treeEnd, int start, int end, int idx){
	// current segment inside the search range
	if(treeStart >= start and treeEnd <= end)
		return st[idx];
	// current segment outside search range
	if(treeStart > end or treeEnd < start)
		return 0;
	int mid = (treeStart + treeEnd) / 2;
	return getSumUtil(st, treeStart, mid, start, end, 2*idx+1)
			+ getSumUtil(st, mid+1, treeEnd, start, end, 2*idx+2);
}

int getSum(int *st, int n, int start, int end){
	if(start < 0 or end > n-1 or start > end){
		cout<<"Error at getSum : invalid index range.\n";
		return 0;
	}
	return getSumUtil(st, 0, n-1, start, end, 0); // search sum from root
}


void updateSTUtil(int arr[], int *st, int start, int end, int arrayIdx, int idx, int diff){
	if(arrayIdx < start or arrayIdx > end)
		return;
	st[idx] += diff;
	if(start != end){
		int mid = (start+end)/2;
		updateSTUtil(arr, st, start, mid, arrayIdx, idx*2+1, diff); // update left child
		updateSTUtil(arr, st, mid+1, end, arrayIdx, idx*2+2, diff); // update right child
	}
}

void updateST(int arr[], int *st, int n, int idx, int val){
	if (idx < 0 || idx > n-1){  
        cout<<"Error at updateST : index out of range.\n";  
        return;
    }
    int diff = val - arr[idx];
    arr[idx] = val;
    updateSTUtil(arr, st, 0, n-1, idx, 0, diff); // update from root
}

int buildSTUtil(int arr[], int *st, int start, int end, int idx){
	if(start == end){
		st[idx] = arr[start];
		return arr[start];
	}
	int mid = (start+end)/2;
	st[idx] = buildSTUtil(arr, st, start, mid, idx*2+1)
				+ buildSTUtil(arr, st, mid+1, end, idx*2+2);
	return st[idx];
}

int *buildST(int arr[], int n){
	int x = (int)(ceil(log2(n)));   
    int max_size = 2*(int)pow(2, x) - 1;  
    int *st = new int[max_size];
    // construct from root tree
    buildSTUtil(arr, st, 0, n-1, 0);

    return st;
}

int main(){
	int arr[] = {1,3,5,2,3,5,91,2,8,2,7};
	int n = sizeof(arr)/sizeof(int);
  
    int *st = buildST(arr, n);

    while(true){
    	cout<<"cmd: ";
    	int cmd; cin>>cmd;
    	if(cmd == 1){
    		cout<<"get sum (l, r): ";
    		int l,r;
    		cin>>l>>r;
    		cout<<getSum(st, n, l, r)<<endl;
    	}else if( cmd == 2){
    		cout<<"update (idx, val): ";
    		int idx, val;
    		cin>>idx>>val;
    		updateST(arr, st, n, idx, val);
    		cout<<"updated.\n";
    	}
    }

    return 0;
}