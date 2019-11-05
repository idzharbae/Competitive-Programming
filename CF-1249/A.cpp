#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

void solve(){
	int n; cin>>n;
	int arr[n+1] = {0};
	arr[0] = INT_MIN;
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	bool flag = false;
	for(int i = 1; i < n; i++){
		if(abs(arr[i]- arr[i-1]) == 1){
			flag = true;
			break;
		}
	}
	if(flag)
		cout<<2<<endl;
	else cout<<1<<endl;

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