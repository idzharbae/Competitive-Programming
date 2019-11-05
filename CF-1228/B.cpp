#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m; cin>>n>>m;
	int r,c;
	int arr[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = 2;
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i = 0; i < n; i++){
		cin>>r;
		for(int j = 0; j < r; j++){
			if(arr[i][j] == 0){
				cout<<0<<endl;
				return 0;
			}
			arr[i][j] = 1;
		}
		if(r == 0){
			if(arr[i][0] == 1){
				// cout<<i<<" "<<arr[i][0]<<endl;
				cout<<0<<endl;
				return 0;
			}else
				arr[i][0] = 0;
		}

	}

	for(int i = 0; i < m; i++){
		cin>>c;
		for(int j = 0; j < n; j++){
			if(arr[j][c] == 0){
				cout<<0<<endl;
				return 0;
			}
			arr[j][c] = 1;
		}

		if(c == 0 and arr[0][c] == 1){
			cout<<0<<endl;
			return 0;
		}
		if(c == 0){
			if(arr[0][i] == 1){
				cout<<0<<endl;
				return 0;
			}else
				arr[0][i] = 0;
		}
	}
	int ans = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = (ans*max(1,arr[i][j]))%1000000007;
	cout<<ans<<endl;
	return 0;
}

