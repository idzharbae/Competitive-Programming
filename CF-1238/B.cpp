#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int n, r; cin>>n>>r;
		set<int> si;
		for(int i = 0; i < n; i++){
			ll x; cin>>x; si.insert(x);
		}
		int shift = 0, ans = 0;
		auto ptr = si.end();
		while(*(--ptr) - shift > 0){
			shift += r;
			ans++;
			// cout<<*ptr<<endl;
			if(ptr == si.begin())
				break;
		}
		// cout<<"ans: ";
		cout<<ans<<endl;

	}

	return 0;
}
