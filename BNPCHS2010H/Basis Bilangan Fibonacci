#include <bits/stdc++.h>
using namespace std;

int fibo[36] = {0,0,0,0,1
,1
,2
,3
,5
,8
,13
,21
,34
,55
,89
,144
,233
,377
,610
,987
,1597
,2584
,4181
,6765
,10946
,17711
,28657
,46368
,75025
,121393
,196418
,317811
,514229
,832040
,1346269, 2178309};

int pre_sum[35] = {0,0,0,0,1,2
,4 
,7 
,12 
,20 
,33 
,54 
,88 
,143 
,232 
,376 
,609 
,986 
,1596 
,2583 
,4180 
,6764 
,10945 
,17710 
,28656 
,46367 
,75024 
,121392 
,196417 
,317810 
,514228 
,832039 
,1346268 
,2178308 
,3524577};

int solve(int n, int N){
	if(N == 0) return 1;
	if(n==0 || N<0) return 0;
	
	int result = 0;
	//cout<<n<<' '<<pre_sum[n]<<endl;
	if(pre_sum[n-1] >= N-fibo[n])
		result += solve(n-1, N-fibo[n]);
	if(pre_sum[n-1] >= N)
		result += solve(n-1, N);
	
	
	return result;
}


int main(){
int T,i;
cin>>T;
while(T--){
	int N;
	cin>>N;
	for(i=0; fibo[i+1] <= N && i < 34; i++);
	//cout<<fibo[i+1]<<" "<<i<<endl;
	cout<<solve(i,N)<<endl;
	//cout<<i;
}
return 0;
}
