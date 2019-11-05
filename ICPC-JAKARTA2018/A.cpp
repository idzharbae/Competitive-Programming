#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;
	int arr[2] = {0};
	for(auto c : s)
		arr[c-'0']++;
	
	if(arr[0] == arr[1]){
		if(s[0] == '0'){
			cout<<'1';
			for(int i = 0; i < s.length() - 1; i++)
				cout<<'0';
		}else{
			cout<<'0';
			for(int i = 0; i < s.length() - 1; i++)
				cout<<'1';
		}
	}
	else{
		char num = ((arr[0] > arr[1])?'1':'0');
		for(int i = 0; i < s.length(); i++)
			cout<<num;
		
	}
	cout<<endl;	

	return 0;
}