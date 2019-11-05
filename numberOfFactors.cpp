#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 2000005
bool isPrime[MAXSIZE];
vector<int> primeFactors[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i = 2; i <= MAXSIZE; i++)
		if(isPrime[]){
			for(int j = 1; j <= MAXSIZE; j++){
				if(i * j > MAXSIZE) break;
				if(j > 1) isPrime[i*j] = 0;
				primeFactors[i*j].push_back(i);
			}
		}

	int q; cin>>q;
	while(q--){
		int n; cin>>n;	
		int factors = 0;
		for(int i = 0; i < primeFactors[n].size(); i++){
			int p = primeFactors[n][i];
			while(n % p){
				factors++;
				n /= p;
			}
		}
		cout<<factors - primeFactors[n].size()<<endl;
	}
	
	return 0;
}