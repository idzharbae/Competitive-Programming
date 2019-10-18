#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef vector<long long> vi;

ll dp[1000000] = {{0}};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n,m; cin>>n>>m;
	ll ans = 1;
	for(int i = m; i <= n; i++){
		memset(dp,0LL,sizeof(dp));
		for(int j = 1; j <= n; j++){
			dp[j] = dp[j-1]+max(j-i+1,0);
			if(j-i-1 >= 0)
				dp[j] += dp[j-i-1];
		}
		ans += dp[n];
	}
	cout<<ans<<endl;
	// solve(i,j) = i-j+1 + solve(i-j,j)
	return 0;
}