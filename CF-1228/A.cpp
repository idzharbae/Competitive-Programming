#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l,r;
	cin>>l>>r;
	for(int i = l; i <= r; i++){
		string s = to_string(i);
		unordered_set<char> c;
		bool flag = true;
		for(auto chr : s){
			if(c.count(chr)){
				flag = false;
				break;
			}
			c.insert(chr);
		}
		if(flag){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;

	return 0;
}