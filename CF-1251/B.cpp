#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

void solve(){
	int n; cin>>n;
	string s[n];
	int odd = 0;
	int tot = 0;
	int cnt[2]={0};
	for(int i = 0; i < n; i++){
		cin>>s[i];
		if(s[i].length() % 2 == 1)
			odd++;
		for(int j = 0; j < s[i].length(); j++)
			cnt[s[i][j] - '0']++;
		tot += s[i].length();
	}
	
	if(odd == 0 and cnt[0] %2 == 1)
		cout<<n-1<<endl;
	else
		cout<<n<<endl;

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