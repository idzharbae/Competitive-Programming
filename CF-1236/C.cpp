#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin>>n;
	int arr[n][n];
	int num = 1;
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			for(int j = 0; j < n; j++){
				arr[j][i] = num;
				num++;
			}
		}else{
			for(int j = n-1; j >= 0; j--){
				arr[j][i] = num;
				num++;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}