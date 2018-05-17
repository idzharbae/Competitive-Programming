#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 

ll gcd(ll a, ll b){
	while(b){
		ll temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	while(n--){
		ll a,b,c; cin>>a>>b>>c;
		ll g = gcd(a,b); a /= g; b /= g;
		while(g = gcd(b,c), g != 1){
			while(b % g == 0) {
                    b /= g;
                }
		}
		if(b != 1) printf("Infinite\n"); else printf("Finite\n");
	}
	
	return 0;
}
