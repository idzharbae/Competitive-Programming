#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<long long> vi;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll x=-1, y=-1, z=0;
 
	if(p/w > n and p%w != 0){
		cout<<-1<<endl;
		return 0;
	}
	if(p%w == 0 and p/w <= n){
		cout<<p/w<<" "<<0<<" "<<n-(p/w)<<endl;
		return 0;
	}
	if(p%d == 0 and p/d <= n){
		cout<<0<<" "<<p/d<<" "<<n-(p/d)<<endl;
		return 0;
	}
	for(int y = 0; y <= w; y++){
		// cout<<y<<endl;
		if(y + (p-(d*y))/w > n){
			break;
		}
		if( (p-(d*y))%w == 0 and (p-(d*y))/w > 0){
			cout<<(p-(d*y))/w<<" "<<y<<" "<<n-y-(p-(d*y))/w<<endl;
			return 0;
		}
	}
 
	cout<<-1<<endl;
	return 0;
}
