#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;


ll f(ll x){
	if(x % 4 == 0)
		return x;
	else if (x % 4 == 1)
		return 1;
	else if (x % 4 == 2)
		return x+1;
	else
		return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll a, b;
		cin>>a>>b;
		cout<<( f(b)^f(a-1) )<<endl;
	}

	return 0;
}