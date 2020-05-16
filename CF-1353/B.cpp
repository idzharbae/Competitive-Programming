#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--) {
		int n, k; cin>>n>>k;
		int a[n], b[n];
		int sumA = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			sumA += a[i];
		}
		for(int i = 0; i < n; i++)
			cin>>b[i];
		sort(a, a+n);
		sort(b, b+n, greater<int>());
		int pref[n+1]; pref[0] = 0;
		for(int i = 1; i <= n; i++)
			pref[i] = max(pref[i-1] + b[i-1] - a[i-1], pref[i-1]);
		cout<<pref[k]+sumA<<endl;
	}

	return 0;
}