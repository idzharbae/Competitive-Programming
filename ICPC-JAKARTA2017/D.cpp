#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	vector<pair<int, pair<int,int> > > tuple;
	for(int i = 0; i < m; i++ ){
		int u,v,w;
		cin>>u>>v>>w;
		tuple.push_back({w, {u,v}});
	}

	sort(tuple.begin(), tuple.end());
	int ans = 0;
	
	for(int i = 0; i < tuple.size(); i++){
		
	}
	

	return 0;
}