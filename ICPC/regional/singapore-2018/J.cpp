#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin>>n;
	int arr[400] = {0};
	for(int i = 0; i < n; i++){
		int a,b;
		cin>>a>>b;
		for(int i = a; i <= b; i++){
			arr[i] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < 400; i++)
		ans += arr[i];
	cout<<ans<<endl;

	return 0;
}