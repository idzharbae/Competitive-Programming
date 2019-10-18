#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll n,m; cin>>n>>m;
		unordered_map<ll,ll, custom_hash> A, B;
		ll C[m];
		for(ll i = 0; i < n; i++){
			ll x; cin>>x;
			if(A.find(x%m) == A.end())
				A[x%m] = x;
			else
				A[x%m] = min(A[x%m], x);
		}
		for(ll i = 0; i < n; i++){
			ll x; cin>>x;
			if(B.find(x%m) == B.end())
				B[x%m] = x;
			else
				B[x%m] = min(B[x%m], x);
		}
		for(ll i = 0; i < m; i++)
			cin>>C[i];
		
		ll ans = LLONG_MAX;
		for(auto it_a = A.begin(); it_a != A.end(); ++it_a){
			ll val_a = (*it_a).second;
			for(auto it_b = B.begin(); it_b != B.end(); ++it_b){
				ll val_b = (*it_b).second;
				ans = min(ans, val_a*val_b + C[(val_a*val_b)%m]);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}