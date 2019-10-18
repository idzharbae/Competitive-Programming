#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll diff = x-y;
		if(diff == 1)
			cout<<"NO\n";
		else
			cout<<"YES\n";

	}


	return 0;
}