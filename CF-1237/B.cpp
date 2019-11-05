#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int prev1[100005];
int prev2[100005];
int next1[100005];
int next2[100005];

// O(1) element deletion with linked list.

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	/* code */
	int n; cin>>n;

	int root1, root2;
	int tail1, tail2;
	int curr1, curr2;
	cin>>root1;
	curr1 = root1;
	for(int i = 1; i < n; i++){
		int x; cin>>x;
		next1[curr1] = x;
		prev1[x] = curr1;
		curr1 = x;
	}
	tail1 = curr1;
	cin>>root2;
	curr2 = root2;
	for(int i = 1; i < n; i++){
		int x; cin>>x;
		next2[curr2] = x;
		prev2[x] = curr2;
		curr2 = x;
	}
	tail2 = curr2;
	
	prev1[root1] = 0;
	prev2[root2] = 0;
	next1[tail1] = 100004;
	next2[tail2] = 100004;

	int ptr1 = tail1;
	int ptr2 = tail2;
	int ans = 0;
	// cout<<"ptr1 = "<<ptr1<<" ptr2 = "<<ptr2<<endl;
	while(ptr1 != 0){
		// cout<<"ptr1 = "<<ptr1<<" ptr2 = "<<ptr2<<endl;
		int temp = ptr2;
		if(ptr1 != ptr2){
			ans++;
			// cout<<ptr1<<" "<<ptr2<<endl;
		}
		else{
			// cout<<"ptr2 from "<<ptr2<<" to ";
			ptr2 = prev2[ptr2];
			// cout<<ptr2<<endl;
		}
		
		prev2[ next2[ptr1] ] = prev2[ptr1];
		next2[ prev2[ptr1] ] = next2[ptr1];

		ptr1 = prev1[ptr1];

	}

	cout<<ans<<endl;
	return 0;
}