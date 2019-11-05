#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;



void solve(){
	int n; cin>>n;
	int arr[n];
	map<int, int> ans;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		arr[i]--;
	}
	
	for(int i = 0; i < n; i++){
		int idx = i;
		int rep = 0;
		vector<int> v;
		v.push_back(idx);
		if(ans[idx] == 0){
			do{
				rep++;
				idx = arr[idx];
				v.push_back(idx);
			} while(idx != i);

		for(int i = 0; i < v.size(); i++)
			ans[v[i]] = rep;
		cout<<rep<<" ";
		}
		else
			cout<<ans[idx]<<" ";
	}
	cout<<endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		solve();
	}

	return 0;
}