#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

ll color[3][100010];
ll dp[4][100010]={0};
ll prv[100010]={0};
ll nxt[100010]={0};
vector< vector<ll> >adj(100001);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n; cin>>n;
	for(ll i = 0; i < 3; i++){
		for(ll j = 0; j < n; j++)
			cin>>color[i][j];
	}
	for(ll i = 0; i < n-1; i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		if(adj[x].size() > 2){
			cout<<-1<<endl;
			return 0;
		}
		adj[y].push_back(x);
		if(adj[y].size() > 2){
			cout<<-1<<endl;
			return 0;
		}
	}
	ll start=-1, finish;
	for(ll i = 0; i < n; i++){
		if(adj[i].size() == 1){
			if(start == -1)
				start = i;
			else
				finish = i;
		}
	}
	ll sstart = start;
	prv[start] = -1;
	nxt[finish] = -1;
	while(start != finish){
		ll nxxt;
		if(adj[start][0] != prv[start]){
			// cout<<"asdf\n";
			nxxt = adj[start][0];
		}
		else{
			// cout<<"test\n";
			nxxt = adj[start][1];
		}

		nxt[start] = nxxt;
		prv[nxxt] = start;
		start = nxxt;
	}

	map<ll,ll> final_cols;
	map<ll,ll> cols;
	ll ans = LLONG_MAX;
	ll ans_col[] = {0,1,2};
	ll curr = 0;
	for(ll i = 0; i < 3; i++){
		ll first = i;
		for(ll sec = 1; sec <= 2; sec++){
			// cout<<"sec = "<<sec<<endl;
			ll second = (first+sec)%3;
			ll third = 3-(first+second);
			ll arr[] = {first,second,third};
			ll curr = 0;

			// for(ll j = 0; j <3; j++)
			// 	cout<<arr[j]<<" "; cout<<endl;
			// cout<<"colors prices:\n";
			ll curr_ans = 0;
			start = sstart;

			while(start != -1){
				cols[start] = arr[curr];
				// cout<<start<<":"<<color[arr[curr]][start]<<" "<<arr[curr]<<" "<<curr<<endl;
				curr_ans += color[arr[curr]][start];
				start = nxt[start];
				curr++; curr %= 3;
			}
			// cout<<endl;
			// cout<<"colors:\n";
			// for(ll j = 0; j < n;j++)
			// 	cout<<cols[i][j]+1<<" ";
			// cout<<endl;
			// cout<<curr_ans<<endl;
			if(ans >= curr_ans){
				ans = curr_ans;
				ans_col[0] = first;
				ans_col[1] = second;
				ans_col[2] = third;
				final_cols = cols;
			}
		}
	}
	cout<<ans<<endl;
	for(auto m : final_cols){
		cout<<m.second+1<<" ";
	}
	cout<<endl;
	// start = sstart;
	// while(start != -1){
	// 	cout<<start<<" ";
	// 	start = nxt[start];
	// }
	// cout<<endl;
	return 0;
}

