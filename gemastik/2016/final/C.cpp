#include <bits/stdc++.h>
using namespace std;

#define MOD 1009
typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		if(x > y)
			cout<<0<<endl;
		else{
			ll ans = 1;
			for(int i = x; i > 0; i--)
				ans = (ans * i) % y;
			cout<<ans%y<<endl;
		}

	}

	return 0;
}