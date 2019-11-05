#include <bits/stdc++.h>
using namespace std;

#define numeric(s) stoll(s, nullptr, 2)
typedef long long ll;
typedef vector<long long> vi;

ll k;


bool check(string s, int x){
	for(int i = 0; i < x; i++){
		if(s.length() == 1){
			return 1 <= k;
		}
		size_t found = s.find("1",1);
		if( found != string::npos)
			s.erase(found,1);
		else
			s.erase(1,1);
	}
	return numeric(s) <= k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	string s;
	cin>>k;
	cin>>s;
	
	int l = 0, r = s.length()+1;

	while(l - r <= 0){
		int m = (l+r)/2;
		if(check(s,m)){
			r = m-1;
		}else{
			l = m+1;
		}
	}
	cout<<l<<endl;

	return 0;
}