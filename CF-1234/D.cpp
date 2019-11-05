#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s; cin>>s;

	vector<set<int> > si(26);
	for (int i = 0; i < s.length(); ++i)
		si[s[i] - 'a'].insert(i);
	
	int q; cin>>q;
	while(q--){
		int cmd; cin>>cmd;
		if(cmd == 1){
			int idx; char c;
			cin>>idx>>c;
			idx--;
			si[s[idx]-'a'].erase(idx);
			si[c-'a'].insert(idx);
			s[idx] = c;
		}else if(cmd == 2){
			int l, r; cin>>l>>r;
			l--; r--;
			int ans = 0;
			for (int i = 0; i < 26; ++i){
				auto lower = si[i].begin();
				lower = si[i].lower_bound(l);
				if(lower != si[i].end() and *lower <= r)
					ans++;
			}
			cout<<ans<<endl;
		}else
			return 0;
		
	}

	return 0;
}