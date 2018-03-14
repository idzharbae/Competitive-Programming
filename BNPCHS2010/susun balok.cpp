#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> set, int n, int sum)
{
    vector<bool> subset[n+1];
	//cout<<"mau masukin bool"<<endl;
    for (int i = 0; i <= n; i++)
      subset[i].push_back(true);
    for (int i = 1; i <= sum; i++)
      subset[0].push_back(false);
    //cout<<"mau masuk loop\n";
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
		  //cout<<"masuk loop "<<i<<" "<<j<<endl;
         if(j<set[i-1])
         subset[i].push_back(subset[i-1][j]);
         if (j >= set[i-1])
           subset[i].push_back(subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]]);
       }
     }
 
  
     return subset[n][sum];
}

int main(){
	int T,N,M,x,i;
	vector <int> H;
	scanf("%d",&T);
	//clock_t begin = clock();
	int j = 0;
	while(T--){
		j = 0;
		int check[1000]={0};
		H.clear();
		scanf("%d%d",&N,&M);
		for(i = 0; i<N; i++){
			scanf("%d",&x);
			if(x <= M && check[x]*x < M){
				H.push_back(x);
				check[x]++;
				//cout<<check[x] * x<<endl;
				j++;
			}
		}
		sort(H.begin(),H.end());
		//cout<<j<<endl;
		//cout<<solve(N-1,M)<<endl;
		if(solve(H,j,M)) printf("YA\n");
		else printf("TIDAK\n");
		//cout<<T<<" "<<N<<" "<<M<<endl;	
		}
	//clock_t end = clock();
	//double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	//cout<<elapsed_secs<<endl;
return 0;
}
