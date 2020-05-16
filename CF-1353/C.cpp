#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--) {
		int n; cin>>n;
		long long ans = 0;
		for(int i = 1; i <= n/2; i++) {
			long long seq1 = (2*(i-1)) + 1, seq2 = (2*i) + 1;
			long long number_of_squares = (2*seq1) + (2*seq2);
			ans += number_of_squares * i;
		}
		cout<<ans<<endl;
	}

	return 0;
}
