#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int q; cin>>q;
	while(q--){
		int n; cin>>n;
    	vector<pair<pair<int,int>, string> > p(n);
    	for (int i = 0; i < n; ++i)
    	{
    		int x,y; string s;
    		cin>>s>>x>>y;
    		p[i] = make_pair(make_pair(x,y), s);
    	}
    	vector<pair<pair<int,int>, string> > p2(n); p2=p;
    	sort(p.begin(), p.end(), [](auto &left, auto &right) {
    		return left.first.first > right.first.first;
		});
		sort(p2.begin(), p2.end(), [](auto &left, auto &right) {
    		return left.first.second > right.first.second;
		});
		set<string> s1;
		set<string> s2;
		int ans = 0, temp1=1,temp2=1;
		int used = 0,i=0,j=0,ii=0,jj=0;
		vector<string> str1, str2;
    	while(ii < 3 && jj < 3){
    		if(s2.count(p[i].second) == 0){
    			temp1 *= p[i].first.first;
    			i++; s1.insert(p[i].second);
    			str1.push_back(p[i].second);
    			ii++;
    		}else{
    			i++;
    		}
    		if(s1.count(p2[j].second) == 0){
    			temp2 *= p2[j].first.second;
    			j++; s2.insert(p2[j].second);
    			jj++;
    			str2.push_back(p2[j].second);
    		}else{
    			j++;
    		}
    	}
    	while(ii < 3){
    		if(s2.count(p[i].second) == 0){
    			temp1 *= p[i].first.first;
    			i++; s1.insert(p[i].second);
    			ii++;
    			str1.push_back(p[i].second);
    		}else{
    			i++;
    		}
    	}

    	while(jj < 3){
    		if(s1.count(p2[j].second) == 0){
    			temp2 *= p2[j].first.second;
    			j++; s2.insert(p2[j].second);
    			jj++;
    			str2.push_back(p2[j].second);
    		}else{
    			j++;
    		}
    	}
    	for(int idx = 0; idx < 3; idx++){
    		cout<<str1[idx]<<((idx==2)?"\n":" ");
    	}
    	for(int idx = 0; idx < 3; idx++){
    		cout<<str2[idx]<<((idx==2)?"\n":" ");
    	}
    	cout<<temp1+temp2<<endl;
	}

	return 0;
}