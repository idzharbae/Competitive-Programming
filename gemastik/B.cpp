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
		int hs,ms,ss,he,me,se;
		map<pair<int,int>, int > m;
		vector<pair<int,int> > window;
		// cout<<"n="<<n<<endl;
		string s;
		int start[n], end[n];
		getline(cin,s);
		for (int i = 0; i < n; ++i){
			getline(cin,s);
			// cout<<s<<endl;
			istringstream f(s);
			char c;
			f>>hs>>c>>ms>>c>>ss>>he>>c>>me>>c>>se;
			start[i] = hs*3600+ms*60+ss;
			end[i] = he*3600+me*60+se;
			// cout<<hs<<" "<<ms<<" "<<ss<<endl;
			// cout<<start<<" "<<end<<endl;
		}
		// sort(window.begin(), window.end());
		int curr = 0;
		int i = 1, j = 0;
		for(int i = 0; i < n; i++){
			int ans = -1;
			int end_max = INT_MIN;
			int start_min = INT_MAX;
			bool flag = false;
			// cout<<"NOW: "<<start[i]<<" "<<end[i]<<endl;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				// cout<<"EEE: "<<start[j]<<" "<<end[j]<<endl;
				if(start[j] <= start[i] and end[j] >= end[i]){
					ans = -1;
					flag = true;
					break;
				}
				if(end[j] >= start[i] and start[j] <= start[i])
					end_max = max(end_max, end[j]);
				if(start[j] <= end[i] and end[j] >= end[i])
					start_min = min(start_min, start[j]);
			}
			if(flag){
				cout<<ans<<endl;
				continue;
			}
			if(start_min < end_max)
				ans = 2;
			else
				ans = 1;
			cout<<ans<<endl;
		}

	}

	return 0;
}