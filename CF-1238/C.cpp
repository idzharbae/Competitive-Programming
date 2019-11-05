#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll h, n;
		cin>>h>>n;
		vi v;
		v.push_back(0);
		v.push_back(h+1);
		for(int i = 0; i < n; i++){
			ll x; cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll cnt = 1;
		ll ans = 0;
		for(int i = 1; i < v.size(); i++){
			if(v[i-1]-v[i] != 1){
				if(cnt & 1)
					ans++;
				cnt = 1;
				continue;
			}
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}