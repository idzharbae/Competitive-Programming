#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int dp[2010][2010];
#define INF 1000000000
#define rep(i,a,n) for(int i = a; i < n; i++) 
#define _set(arr, val) for(unsigned i = 0; i < (sizeof arr)/(sizeof arr[0]); i++) arr[i] = val;
#define _set2d(arr, val) for(unsigned i = 0; i < (sizeof arr)/(sizeof arr[0]); i++) for(unsigned j = 0; j < (sizeof arr[0])/(sizeof arr[0][0]); j++) arr[i][j] = val;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,n,m; cin>>a>>n>>m;
	bool rain[2010]; int umb[2010];
	_set(rain,false); _set(umb,INF);
	
	for(int i = 0; i < n; i++){
		int l,r; cin>>l>>r;
		for(int j = l; j < r; j++)								// r tidak dimasukkan karna anggapannya pas udah diujung dan kita 
			rain[j] = true;										// megang umberella, kita bisa move ke tile selanjutnya tanpa megang
	}															// umberella
	for(int i = 0; i < m; i++){
		int x,y; cin>>x>>y;
		umb[x] = min(umb[x],y);
	}
	_set2d(dp,INF); dp[0][a+2] = 0;
	int loop = 0;
	for(int i = 0; i < a; i++){
		for(int j = 0; j <= a+2; j++){
			// current state = dp[i][j]
			loop++;
			if(dp[i][j] == INF) continue;						// jika state sekarang tidak memenuhi constraint, skip.
			if(!rain[i])
				dp[i+1][a+2] = min(dp[i+1][a+2],dp[i][j]); 		// klw skrg ga rain kita bisa move ke tile selanjutnya tanpa umberella.
			if(j < a+2)											// jika state sekarang megang umberella, update state slanjutnya.
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]+umb[j]);	
			if(umb[i] != INF)									// jika ada umberella di koordinate ini, consider picking it and change state.
				dp[i+1][i] = min(dp[i+1][i], dp[i][j]+umb[i]);
		}
	}
	
	int ans = INF;
	for(int i = 0; i <= a+2; i++) ans = min(ans, dp[a][i]);
	if(ans == INF) ans = -1;
	cout<<ans<<endl;
	return 0;
}

