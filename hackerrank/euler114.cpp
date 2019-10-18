#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define MOD (1000000007)

ll F[100][100], M[100][100];
ll n,m;

void multiply(ll a[100][100], ll b[100][100]) 
{ 
	ll mul[100][100];
    for (ll i = 0; i < m; i++) 
    { 
        for (ll j = 0; j < m; j++) 
        { 
            mul[i][j] = 0; 
            for (ll k = 0; k < m; k++) {
                mul[i][j] += (a[i][k]*b[k][j])%MOD; 
                mul[i][j] %= MOD;
            }
        } 
    }
    for(int i = 0; i < m; i++)
    	for(int j = 0; j < m; j++)
    		a[i][j] = mul[i][j];

} 
  
ll power(ll p) 
{ 
	ll ans = 0;
	if(p == 0) return 1;
	while(p){
		if(p%2)
			multiply(F,M);
		multiply(M,M);
		p/=2;
	}
	for(ll i = 0; i < m; i++)
		ans += F[0][i];
	return ans;
} 

int main(){
	cin>>n>>m;
	for(ll i = 0; i < 100; i++){
		for(ll j = 0 ; j < 100; j++){
			if(i == 0){
				if(j == 0 || j == m-1)
					M[i][j] = 1;
			}else if(i-1 == j)
				M[i][j] = 1;
			else
				M[i][j] = 0;
		}
	}
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++){
			if(i == j) F[i][j] = 1;
			else F[i][j] = 0;
		}
	// if n < m we cant split any marbles
	if(n < m){
		cout<<1<<endl;
		return 0;
	}
	/*	Simple DP solution : 
		for(ll i = m; i <= n+m; i++)
			dp[i] = (dp[i-1]%MOD + dp[i-m]%MOD)%MOD;
		But the limit is very large so the memory cant handle to store them all.
		We need to transform the recurrence into a matrix exponentiation instead,
		reallocating the burden from memory to computation time.
	*/

	// when n = m, we can either not split any magic marbles, or have one magic marbles then split it to m normal marbles.
	// hence, when n = m, the answer is 
	/*cout<<"POW="<<n-m+1<<endl;
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++)
			cout<<F[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	cout<<power(n-m+1)%MOD<<endl;
	/*
	cout<<endl;
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++)
			cout<<F[i][j]<<" ";
		cout<<endl;
	}*/
	
	return 0;
}