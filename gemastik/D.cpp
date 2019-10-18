#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

bool check(int l, int b, int k){
	int edges = 2*k;
	int mids = k+1;
	int sub = min(edges, b);
	b -= sub;
	edges -= sub;
	sub = min(mids/2, b);
	b -= sub;
	mids -= sub*2;
	if(b > 0)
		return false;
	if(edges + mids < l)
		return false;

	return true;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int l,b;
		cin>>l>>b;
		for(int ans = 1; ans <= 100; ans++){
			if(check(l,b,ans) or ans == 100){
				cout<<ans<<endl;
				break;
			}
		}
	}

	return 0;
}