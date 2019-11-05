#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

// 100% - Probabilitas diantara 3 orang lain tidak ada yang punya kartu di bawah nilai kartu X untuk jenis Y
map<char, int> dict = { {'D', 0}, {'C', 1}, {'H', 2}, {'S', 3} };
vector<int> arr[4];

int nCk(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previously 
            // stored values 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

void solve(){
	bool available[4][13]= {{0}};
	for(int i = 0; i < 4; i++)
		for(int j = 2; j <= 14; j++){
			available[i][j-2] = true;
			arr[i].push_back(j);
		}
		
	string s[13];
	for(int i = 0; i < 13; i++){
		cin>>s[i];
		int jenis = dict[s[i][1]];
		char c = s[i][0];
		switch(c){
			case 'T':
				available[10] = 0;;
				break;
			case 'J':
				available[11]=  0;
				break;
			case 'Q':
				available[12] = 0;
				break;
			case 'K':
				available[13] = 0;
				break;
			case 'A':
				available[14] = 0;
				break;
			default:
				available[c-'0'] = 0;
		}
	}
	cout<<setprecision(5)<<fixed;

	for(int i = 0 ; i < 13; i++){
		long double win = 0;
		int num, jenis = dict[s[i][1]];
		int all = 39*26*13;
		char c = s[i][0];
		switch(c){
			case 'T':
				num = 10;
				break;
			case 'J':
				num = 11;
				break;
			case 'Q':
				num = 12;
				break;
			case 'K':
				num = 13;
				break;
			case 'A':
				num = 14;
				break;
			default:
				num = c - '0';
		}

		for(int j = 0; j < 52; j++){
			int min_j = -1, min_k = -1, min_l = -1;
			for(int k = 0; k < 52; k++){
				min_k = -1;
				for(int l = 0; l < 52; l++){
					min_l = -1;
				}
			}
		}
		cout<<s[i]<<": "<<100*win/all<<"%\n";
	}

	for(int i = 0; i < 4; i++)
		arr[i].clear();

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		solve();
		if(q != 0)
			cout<<endl;
	}

	return 0;
}