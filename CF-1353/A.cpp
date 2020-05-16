#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin>>q;
	while(q--) {
		int n, m; cin>>n>>m;
		int ans;
		if(n == 1) ans = 0;
		else if(n == 2) ans = m;
		else ans = 2*m;
		cout<<ans<<endl;
	}
	return 0;
}

