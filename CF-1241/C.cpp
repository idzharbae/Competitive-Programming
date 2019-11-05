#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long calc(ll p[], int len, ll k, ll x, ll y, ll a, ll b){
	ll cX=0, cY=0, cXY=0;
	for(int i = 1; i <= len; i++){
		if(i%a ==0  and i%b == 0)
			cXY++;
		else if(i%a == 0)
			cX++;
		else if(i%b == 0)
			cY++;
	}
	ll ans = 0;
	// cout<<cXY<<" "<<cX<<" "<<cY<<endl;
	for(int i = 0; i < len; i++){
		if(cXY){
			cXY--;
			ans += p[i]*(x+y)/100;
		}
		else if(cX){
			cX--;
			ans += p[i]*x/100;
		}
		else if(cY){
			cY--;
			ans += p[i]*y/100;
		}
	}
	// cout<<ans<<" "<<len<<endl;
	return ans;
}

int main(){
	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		ll p[n],k;
		for(int i = 0; i < n; i++)
			cin>>p[i];
		ll x,y,a,b;
		cin>>x>>a>>y>>b;
		cin>>k;
		sort(p, p+n, greater<ll>());
		if(x < y){
			ll temp = x;
			x = y;
			y = temp;
			temp = a;
			a = b;
			b = temp;
		}

		int l = 0, r = n+1;
		while(l-r < 1){
			int m = l + (r-l) / 2;
			ll res = calc(p, m, k, x, y, a, b);
			if( k > res )
				l = m+1;
			else
				r = m-1;
		}
		if(l < 1 or l > n)
			l = -1;
		cout<<l<<endl;
	}

	return 0;
}