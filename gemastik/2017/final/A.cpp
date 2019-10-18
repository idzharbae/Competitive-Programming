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
		string query[n];
		getline(cin, query[0]);
		for(int i = 0; i < n; i++)
			getline(cin, query[i]);
		set<string> names;
		for(int i = 0; i < n; i++){
			stringstream ss(query[i]);
			string buf; int n;
			ss>>buf>>n;
			while(n--){
				string name; ss>>name;
				names.insert(name);
			}
		}
		int ans = names.size();
		for(int i = 0; i < n; i++){
			stringstream ss(query[i]);
			string buf; int n;
			ss>>buf>>n;
			if(buf == "dibantu" and n == ans){
				ans++;
				break;
			}
		}
		cout<<ans<<endl;

	}

	return 0;
}