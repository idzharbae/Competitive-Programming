#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans = 0;

		while(c-2 >= 0 and b-1 >= 0){
			ans += 2+1;
			c-=2; b-=1;
		}
		while(b-2 >= 0 and a-1 >= 0){
			ans += 2+1;
			b-=2; a-=1;
		}
		cout<<ans<<endl;
	}

	return 0;
}