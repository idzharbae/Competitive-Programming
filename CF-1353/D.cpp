#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

struct segmentPriority
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        int diffA = a.second - a.first, diffB = b.second - b.first;
		if(diffA != diffB)
			return diffA < diffB;
		return a.first > b.first;
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin>>t; 
	while(t--) {
		int idx = 1;
		int n; cin>>n;
		vector<int> v(n, 0);
		int l = 1, r = n;
		priority_queue<pair<int,int>, vector<pair<int,int>>, segmentPriority> q;
		q.push({l,r});
		while(!q.empty()) {
			pair<int,int> s = q.top(); q.pop();
			l = s.first, r = s.second;
			int m = (l+r)/2;
			v[m-1] = idx++;

			if(m-1 >= l)
				q.push({l,m-1});
			if(m+1 <= r)
				q.push({m+1,r});
		}
		for(int i = 0; i < n; i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}

	return 0;
}
