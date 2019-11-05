#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

struct lst{
	char c;
	struct lst* prev;
	struct lst* nxt;
};
typedef struct lst lst;

void solve(){
	string s; cin>>s;
	string odd = "";
	string even = "";
	for(int i = 0; i < s.length(); i++){
		int num = s[i]-'0';
		if( num %2 )
			odd+=s[i];
		else
			even+=s[i];
	}
	string res = "";
	int i = 0, j = 0;
	while(i < odd.length() and j < even.length()){
		if( odd[i] < even[j] ){
			res += odd[i];
			i++;
		}else{
			res += even[j];
			j++;
		}

	}
	while(i < odd.length()){
		res += odd[i];
		i++;
	}
	while(j < even.length()){
		res += even[j];
		j++;
	}
	cout<<res<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}