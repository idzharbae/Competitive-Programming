#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, M, D;

ll f(ll x, ll rep){
	ll temp = 0;
	for(int i = 0; i < rep-1; i++){
		if(temp + x*k > n or temp + x*k < 0) return false; // kalau penjumlahan, hasilnya paling banyak lebih lebar 1 bit dari panjang bilangan sebelumnya yg lebih besar;
		temp += x*k;
		// cout<<temp<<endl;
	}
	if(temp + x > n or temp + x < 0) return false;
	// if(k*x*(rep-1)+x <= n) return true;
	// cout<<ans<<endl;
	return true;
}

int main(){
	cin>>n>>k>>M>>D;
	ll ans = 0;
	for(int i = 1; i <= D; i++){
		ll  l = 1, r = M, mid = (l+r)/2; 
		while(l<=r){
			// cout<<mid<<endl;
			if(f(mid, i)) l = mid + 1;
			else r = mid - 1;
			mid = (l+r)/2;
		}
		// cout<<r<<" "<<i<<" "<<r*i<<endl;
		if(ans < r*i){ ans = r*i;}
	}
	cout<<ans<<endl;
	
	
    
    return 0;
}
