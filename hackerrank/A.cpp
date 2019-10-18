#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		int a,b,c;
		int maks = 0, mins = 0;
		for(int i = 0; i < n; i++){
			cin>>a>>b>>c;
			maks += max(a,max(b,c));
			mins += min(a,min(b,c));
		}
		cout<<mins<<" "<<maks<<endl;
	}

	return 0;
}