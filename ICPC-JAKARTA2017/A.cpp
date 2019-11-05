#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin>>n>>m;
	int arr[m];
	for(int i = 0; i < m; i++)
		cin>>arr[i];
	int winner = 0;
	int maks = 0;
	for(int i = 0; i < n ; i++){
		int score = 0;
		for(int j = 0; j < m; j++){
			int x; cin>>x;
			if(x == arr[j])
				score++;
		}
		if(score > maks){
			winner = i;
			maks = score;
		}
	}
	cout<<1+winner<<endl;
	return 0;
}