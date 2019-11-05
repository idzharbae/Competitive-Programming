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

	ll n; cin>>n;
	ll arr[n+1];
	unordered_map<ll, ll, custom_hash> dp;
	ll ans = 0, val = -1;
	for(ll i = 1; i <= n; i++){
		cin>>arr[i];
		dp[arr[i]] = dp[arr[i]-1] + 1; // gausah cek apakah idx lebih kecil karna idx yg lebih gede masih blm masuk
		if(ans < dp[arr[i]]){
			ans = dp[arr[i]];
			val = arr[i];
		}
	}
	cout<<ans<<endl;
	vector<int> index;
	for(int i = n; i > 0; i--){
		if(arr[i] == val){
			index.push_back(i);
			val--;
		}
	}
	for(int i = index.size()-1; i >= 0; i--)
		cout<<index[i]<<" ";
	cout<<endl;

	return 0;
}