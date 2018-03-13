#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,N,M,mod = 10000;
	cin>>T;
	while(T--){
		cin>>N>>M;
		if(M==N){
			cout<<'1'<<endl;
			continue;
		}
		if(M==0) M=2;
		int k[11111] = {0};
		k[M+10] = 1;
		for(int i=M+10; i<=N+10; i++){
			k[i] += (k[i-1]%mod + k[i-2]%mod)%mod;
			//cout<<"k[i-1] = "<<k[i-1]<<' '<<"k[i-2] = "<<k[i-2]<<endl;
		}
		cout<<k[N+10]<<endl;
	}
	
return 0;
}
