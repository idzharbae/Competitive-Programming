#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		string s; cin>>s;
		ll furthest = -1;
		ll nearest = s.length();
		for(ll i = 0; i < s.length(); i++){
			if(s[i] == '1'){
				furthest = max(furthest, i);
				nearest = min(nearest, i);
			}
		}
		if(furthest == -1 and nearest == s.length())
			cout<<n<<endl;
		else
			cout<<max((n-nearest)*2, (furthest+1)*2)<<endl;
	}

	return 0;
}