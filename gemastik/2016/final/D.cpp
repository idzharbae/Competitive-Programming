#include <bits/stdc++.h>
using namespace std;

#define MOD 1009
typedef long long ll;
typedef vector<long long> vi;

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll n,m;
		cin>>n>>m;
		ll size_kiri[n]={0}, size_kanan[n]={0};
		ll pref_kiri[n] = {0}, pref_kanan[n] = {0};
		// cout<<"n = "<<n<<" m = "<<m<<endl;
		for(ll i = 0; i < m; i++){
			ll x,k;
			cin>>x>>k; x--;
			// cout<<x<<" "<<k<<endl;
			ll start_idx, end_idx;
			ll start_height, end_height;
			
			// angin ke kiri
			start_idx = max(0LL, x-k);
			start_height = start_idx - (x-k);
			end_idx = x;
			end_height = k;
			// cout<<"kiri\n";
			// cout<<start_idx<<" "<<start_height<<endl;
			// cout<<end_idx<<" "<<end_height<<endl;

			size_kiri[start_idx]++;
			pref_kiri[start_idx] += start_height;
			size_kanan[end_idx]++;
			pref_kanan[end_idx] += end_height;
			
			// angin ke kanan
			if(x+1 < n){
				if(k > 1){
					start_idx = x+1;
					start_height = k-1;
					end_idx = min(x+k, n-1);
					end_height = x+k - min(x+k, n-1);
					// cout<<"kanan\n";
					// cout<<start_idx<<" "<<start_height<<endl;
					// cout<<end_idx<<" "<<end_height<<endl;
					size_kiri[start_idx]--;
					pref_kiri[start_idx] += start_height;
					size_kanan[end_idx]--;
					pref_kanan[end_idx] += end_height;
				}
			}
		}
		ll height = 0, num = 0;
		for(ll i = 0; i < n; i++){
			height += pref_kiri[i];
			cout<<height<<((i == n-1)?"\n":" ");
			height -= pref_kanan[i];
			num += size_kiri[i];
			num -= size_kanan[i];
			height += num;
		}

	}

	return 0;
}