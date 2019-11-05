#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int n,k; cin>>n>>k;
	int ans = 0;
	vector<int> vans;
	vector<pair<int,int> > v[256];
	int arr[256] = {0};
	for(int i = 1; i <= n; i++){
		// cout<<i<<endl;
		int l, r; cin>>l>>r;
		
		for(int j = l; j <= r; j++){
			v[j].push_back({{l,r},i});
			arr[j]++;
		}
	}
	for(int i = 1; i <= 200; i++){
		// cout<<i<<endl;
		while(arr[i] > k){
			cout<<i<<" "<<arr[i]<<endl;
			ans++;
			pair<int,int> p;
			int max_len = -1;
			int idx = -1;
			for(int j = 0; j < v[i].size(); j++){
				int len = v[i][j].second - v[i][j].first;
				if(max_len < len){
					max_len = len;
					p = v[i][j];
					idx = j+1;
				}
			}
			vans.push_back(idx);
			int l = p.first, r = p.second;
			v[i].pop_back();
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				v[j].erase( find(v[j].begin(), v[j].end(), p) );
			}
			for(int j = l; j <= r; j++)
				arr[j]--;
			
			cout<<endl;
		}
	}
	cout<<ans<<endl;
	for(int i = 0; i < vans.size(); i++)
		cout<<vans[i]<<" ";
	cout<<endl;
	return 0;
}