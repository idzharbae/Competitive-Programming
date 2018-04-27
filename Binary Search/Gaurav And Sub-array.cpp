#include <bits/stdc++.h>
using namespace std;
unsigned int pref[100005], N,  Q, K;
int ones(unsigned int u)
{
     unsigned int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

int f(int l){
	int sum = 0;
	for(int i = l; i <= N;i++){
		sum = pref[i] - pref[i-l];
		if(sum >= K) return true;
	}
	return false;
}

int main(){
	pref[0] = 0;
    cin>>N>>Q;
    unsigned int x;
    for(int i = 1; i <= N; i++){
		cin>>x;
		pref[i] = pref[i-1] + ones(x); // array store prefix sum of total ones
	}
	while(Q--){
		cin>>K;
		int l = 1, r = N, mid = (l+r)/2;
		while(l<=r){
			if(f(mid)) r = mid - 1;
			else l = mid + 1;
			mid = (l+r)/2;
		}
		if (l>N or l < 1) cout<<-1<<endl;
		else
		cout<<l<<endl;
	}
    
    return 0;
}
