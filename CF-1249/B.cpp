#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		arr[i]--;
	}
	
	for(int i = 0; i < n; i++){
		int idx = i;
		int rep = 0;
		do{
			rep++;
			idx = arr[idx];
		} while(idx != i);
		cout<<rep<<" ";
	}
	cout<<endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		solve();
	}

	return 0;
}