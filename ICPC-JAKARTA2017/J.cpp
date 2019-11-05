#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k,t; cin>>n>>k>>t;
	int arr[n];
	map<int,int> m;
	for(int i = 0; i < n; i++){
		int x; cin>>x; 
		m[x]++;
	}
	if(n < k){
		cout<<-1<<endl;
		return 0;
	}
	if(n == k){
		cout<<0<<endl;
		return 0;
	}

	int emp = 0;
	pair<int, int> ptr;
	for(auto mm : m){
		emp += mm.second;
		if(emp >= k){
			ptr = mm;
			break;
		}
	}
	if(emp == k){
		cout<<0<<endl;
		return 0;
	}
	int ans = -1;
	// bisa dimajuin
	if(ptr.first < t){
		ans = emp - k;
	}
	// bisa di mundurin
	if(ptr.first > 0){
		int cost = ptr.second - (emp - k);
		if(ans == -1)
			ans = cost;
		else
			ans = min(cost, ans);
	}
	cout<<ans<<endl;
	return 0;
}