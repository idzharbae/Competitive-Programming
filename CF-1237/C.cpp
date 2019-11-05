#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second.first
#define Z second.second

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin>>n;
	vector<pair<int, pair<int,int> > > v(n);
	for(int i = 0; i < n; i++){
		int x,y,z; cin>>x>>y>>z;
		x--; y--; z--;
		v[i] = {x,{y,z}};
	}
	bool deleted[2048] = {0};
	for(int i = 0; i < n; i++){
		if(deleted[i])
			continue;
		int idx = 0;
		pair<int,int> curr;
		do{
			idx++;
			curr = {i,i+idx};
			// cout<<i<<" "<<i+idx<<endl;
		} while(deleted[i+idx] and i+idx < n);
		if(deleted[curr.second] or deleted[curr.first])
			continue;
		for(int j = i+idx; j < n; j++){
			if(deleted[j])
				continue;
			if(
				( v[j].X >= min( v[curr.first].X, v[curr.second].X) and
				  v[j].X <= max( v[curr.first].X, v[curr.second].X) and
				  v[j].Y >= min( v[curr.first].Y, v[curr.second].Y) and
				  v[j].Y <= max( v[curr.first].Y, v[curr.second].Y) and
				  v[j].Z >= min( v[curr.first].Z, v[curr.second].Z) and
				  v[j].Z <= max( v[curr.first].Z, v[curr.second].Z) )
				) curr = {i, j};
		}
		// cout<<deleted[curr.first]<<" "<<deleted[curr.second]<<endl;
		deleted[curr.first] = true;
		deleted[curr.second] = true;
		cout<<curr.first+1<<" "<<curr.second+1<<endl;
	}


	return 0;
}