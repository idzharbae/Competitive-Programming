#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

// COUNTING INVERSION WITH BINARY INDEXED TREE
// TIME COMPLEXITY : 0(N LOG MAX_ELEMENT)
// AUXILIARY SPACE : O(MAX_ELEMENT)

int getSum(int BIT[], int index) { 
	int sum = 0;
	while(index > 0){
		sum += BIT[index];
		index -= index & (-index);
	}
	return sum;
} 
  
void updateBIT(int BIT[], int n, int index, int val) { 
	while(index <= n){
		BIT[index] += val;
		index += index & (-index);
	}
} 
  
int getInvCount(int arr[], int n) 
{ 
    int invcount = 0; 
  	
  	// use array value as index
    // BIT nya sendiri bwt ngitung berapa banyak element sebelum arr[i]

    int maxElement = *max_element(arr+1, arr+n+1);
    int BIT[maxElement+1] = {0};
  
    
    for (int i=n; i>=1; i--){
    	invcount += getSum(BIT, arr[i]-1);
    	updateBIT(BIT, n, arr[i], 1);
    }
  
    return invcount; 
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int n;
		cin>>n;
		int arr[n+1];
		for(int i = 1; i <= n; i++)
			cin>>arr[i];
		cout<<((getInvCount(arr,n)%2)?"TIDAK":"YA")<<endl;
	}

	return 0;
}