#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--) {
		long long n, k; cin>>n>>k;
		string s; cin>>s;
		s = "0"+s;
		// dp[i][j] = k-periodic string with length i ending with character j
		long long dp[n+1][2]; dp[0][0] = dp[0][1] = 0;
		long long pref[n+1]; pref[0] = 0;

		for(long long i = 1; i <= n; i++) {
			pref[i] = pref[i-1] + (s[i] == '1');
			// current char is 0, doesn't matter what the previous char is, take the minimum.
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + (s[i] != '0');
			// current char is 1, either 0 all previous chars or pick latest 1 occurence 
			// then convert all 1s after that to 0
			long long dp_i_k = (i-k >= 0)?dp[i-k][1]:0;
			long long pref_i_k = (i-k >= 0)?pref[i-k]:0;
			dp[i][1] = min(dp_i_k + pref[i-1] - pref_i_k, pref[i-1])  + (s[i] != '1');
		}
		cout<<min(dp[n][0], dp[n][1])<<endl;
	}

	return 0;
}