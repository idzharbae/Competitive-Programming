#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

ll dp[1001][1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll n,s,p;
		cin>>n>>s>>p;
		ll k[n+1]={0}, v[n+1]={0}, item[s+1]={0};
		for(ll i = 1; i <= n-1; i++)
			cin>>k[i]>>v[i];
		
		for(ll i = 0; i <= n-1; i++){
			for(ll j = 0; j <= s; j++){
				if(i == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = -1;
			}
		}
		for(ll i = 1; i <= n-1; i++){
			for(ll j = 0; j <= s; j++){
				dp[i][j] = -1;
				if(j > 0)
					dp[i][j] = dp[i][j-1];
				if(j - k[i] >= 0 and dp[i-1][j-k[i]] != -1)
					dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-k[i]]);
				if(j - p >= 0)
					dp[i][j] = max(dp[i][j],item[j-p]);
				item[j] = max(item[j], dp[i][j]);
			}
		}
		
		cout<<dp[n-1][s]<<endl;
	}

	return 0;
}