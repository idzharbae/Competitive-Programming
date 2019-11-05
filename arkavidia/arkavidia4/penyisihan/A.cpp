#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		ll ans = 0;
		ll mins = LLONG_MAX;
		ll arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			mins = min(mins, arr[i]);
		}
		for(int i = 0 ; i < n ; i++)
			ans += arr[i] - mins;
		cout<<ans<<endl;

	}

	return 0;
}