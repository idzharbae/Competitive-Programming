#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 2000004
bool isPrime[MAXSIZE+1];
vector<int> primeFactors[MAXSIZE+1];

int main(){

	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i = 2; i <= MAXSIZE; i++)
		if(isPrime[i]){
			for(int j = 1; j <= MAXSIZE; j++){
				if(i * j > MAXSIZE) break;
				if(j > 1) isPrime[i*j] = 0;
				primeFactors[i*j].push_back(i);
			}
		}

	int q; cin>>q;
	while(q--){
		int n; cin>>n;	
		int temp = n;
		int factors = 1;
		for(int i = 0; i < primeFactors[n].size(); i++){
			int p = primeFactors[n][i];
			int count = 0;
			while(temp % p == 0){
				count++;
				temp /= p;
			}
			factors *= (count+1);
		}
		// cout<<endl;
		int pfactors = primeFactors[n].size();
		// cout<<factors<<" "<<pfactors<<endl;
		cout<<factors - pfactors<<endl;
	}
	
	return 0;
}