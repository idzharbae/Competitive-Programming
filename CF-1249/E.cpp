#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, c; cin>>n>>c;
	ll stair[n] = {0LL}, ele[n] = {0LL};
	for(int i = 1; i < n; i++)
		cin>>stair[i];
	for(int i = 1; i < n; i++)
		cin>>ele[i];
	ll dp[n+1][2] = {{0}};
	// 0 = tangga
	// 1 = ele
	// for(int i = 1; i <= n; i++)
	// 	cout<<stair[i]<<" ";
	// cout<<endl;
	// for(int i = 1; i <= n; i++)
	// 	cout<<ele[i]<<" ";
	// cout<<endl;
	// cout<<" N = "<<n<<endl;
	// cout<<" C = "<<c<<endl;
	for(int i = 1; i < n; i++){
		dp[i][0] += min(dp[i-1][0], dp[i-1][1]) + stair[i];
		dp[i][1] += min(dp[i-1][0], max(dp[i-1][1] - c, 0LL) ) + ele[i] + c;
	}

	// for(int i = 0; i < n; i++)
	// 	cout<<dp[i][0]<<" ";
	// cout<<endl;
	// for(int i = 0; i < n; i++)
	// 	cout<<dp[i][1]<<" ";
	// cout<<endl<<endl;
	for(int i = 0; i < n; i++)
		cout<<min(dp[i][1], dp[i][0])<<" ";
	cout<<endl;
	return 0;
}