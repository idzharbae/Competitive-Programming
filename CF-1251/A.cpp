#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		string s; cin>>s;
		int n = s.length();
		map<char, bool> m;
		s += "!";
		int cnt = 0;
		char curr = '!';
		for(int i = 0; i < 26; i++)
			m['0'+i] = false;
		for(int i = 0; i < s.length(); i++){
			// cout<<curr<<" "<<s[i]<<" "<<cnt<<endl;
			if(curr != s[i]){
				if(i == 0){
					cnt = 1;
					curr = s[i];	
					continue;
				} 
				if(cnt%2 == 1)
					m[curr] = true;
				cnt = 1;
				curr = s[i];
			}else cnt++;
		}
		for(auto mm : m)
			if(mm.second == true)
				cout<<mm.first;
		cout<<endl;
	}

	return 0;
}