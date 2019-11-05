#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

// vector<ll> v;
ll bit=0;
ll mins = 0;
ll maks = 0;

ll xpow(ll a, ll b){
	ll ans = 1;
	for(int i = 0; i < b; i++)
		ans *= a;
	return ans;
}

ll calc(ll m){
	ll ans = 0;
	ll idx = 0;
	while(m){
		ans += xpow(3LL,idx)*(m & 1);
		m = m >> 1;
		idx++;
	}

	return ans;
}

void solve(){
	ll n; 
	cin>>n;
	ll l = 0, r = (1LL<<41)-1;
	while(l <= r){
		ll m = (l+r)/2;
		ll yes = calc(m);
		// cout<<m<<" "<<calc(m)<<endl;
		// cout<<m<<" "<<yes<<endl;
		if( yes < n){
			l = m + 1;
		}else
			r = m - 1;
	}
	cout<<calc(l)<<endl;
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