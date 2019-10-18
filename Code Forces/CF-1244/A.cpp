#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int a,b,
			c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x = a/c + (a%c > 0),
		    y = b/d + (b%d > 0);
		if(x+y > k)
			cout<<-1<<endl;
		else
			cout<<x<<" "<<y<<endl;
	}

	return 0;
}