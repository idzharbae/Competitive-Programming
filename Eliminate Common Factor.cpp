#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define rep(i,a,n) for(int i = a; i < n; i++) 

ll gcd(ll a, ll b) {
    return (b == 0? a: gcd(b, a % b));
}

int main(){
	int n; scanf("%d", &n);
	while(n--){
		ll a,b,c;scanf("%I64d%I64d%I64d", &a,&b,&c);
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

