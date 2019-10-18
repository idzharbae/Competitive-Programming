#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define inf LLONG_MAX

typedef long long ll;
typedef vector<long long> vi;

ll arr[64][64];
ll dp[64][64];
int r,c,n;
int x[] = {0,0,1,-1};
int y[] = {-1,1,0,0};

// Djikstra dengan priority queue
// Utamakan jarak terjauh dulu ( push negative value ) untuk menghindari TLE

ll djikstra(pair<int,int> s){
	priority_queue< pair<ll, pair<int,int> > > q;
    q.push({-1LL, {s.first, s.second}});
    for(int i = 0; i <= r; i++)
    	for(int j = 0; j <= c; j++)
    		dp[i][j] = INT_MAX;

    dp[s.first][s.second] = 1;

    while (!q.empty()) {
    	pair<ll,pair<int,int> > tp = q.top(); q.pop();
        pair<int,int> v = tp.second; 
        ll dist = -tp.first;
        for (int i = 0; i < 4; i++) {
            int xx = v.first+x[i], yy = v.second+y[i];
            if(xx <= 0 or xx > r or yy <= 0 or yy > c)
            	continue;
            if (dp[xx][yy] > 1+dist + abs(arr[xx][yy] - arr[v.first][v.second]) ) {
                dp[xx][yy] = 1+dist + abs(arr[xx][yy] - arr[v.first][v.second]) ;
                q.push({-dp[xx][yy], {xx,yy}});
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= c; i++)
    	ans = (ans + (dp[1][i])%MOD ) % MOD;
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		cin>>r>>c>>n;
		pair<int,int> src;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++){
				cin>>arr[i][j];
				if(arr[i][j] == -1){
					src = make_pair(i,j);
					arr[i][j] = 0;
				}
			}
		ll ans = 0;
		ans = djikstra(src);
		cout<<ans<<endl;

	}

	return 0;
}