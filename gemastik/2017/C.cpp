#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int n; 
int s[64], p[64], c[64][64];
bool adj[2500][64];

bool bpm(int u, bool seen[], int matchR[]){
	for (int v = 0; v < 2500; v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (adj[v][u] && !seen[v]) 
        { 
            // Mark v as visited 
            seen[v] = true;  
  
            // If job 'v' is not assigned to an  
            // applicant OR previously assigned  
            // applicant for job v (which is matchR[v])  
            // has an alternate job available.  
            // Since v is marked as visited in  
            // the above line, matchR[v] in the following  
            // recursive call will not get job 'v' again 
            if (matchR[v] < 0 || bpm(matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                // cout<<"perusahaan "<<u+1<<" dapet soal "<<v%50+1<<" dari penulis "<<v/50+1<<endl;
                return true; 
            } 
        } 
    } 
    return false; 
}

ll maxBPM(){
	int matchR[2500]; 
  
    // Initially all jobs are available 
    memset(matchR, -1, sizeof(matchR)); 
  
    // Count of jobs assigned to applicants 
    ll result = 0;  
    for (int u = 0; u < 50; u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        bool seen[2500]; 
        memset(seen, 0, sizeof(seen)); 
  
        // Find if the applicant 'u' can get a job 
        if (bpm(u, seen, matchR)) 
            result++; 
    } 
    return result; 
}

void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s[i];
		s[i]--;
	}

	for(int i = 0; i < n; i++){ 
		cin>>p[i];
		for(int j = 0; j < p[i]; j++){
			cin>>c[i][j]; // perusahaan ke-j dari penulis i;
			c[i][j]--;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i]; j++){ // distribusi soal milik penulis ke-i
			for(int k = 0; k < p[i]; k++){
				adj[i*50+j][c[i][k]] = 1; // perusahaan c[i][j] punya akses ke soal ke-j dari penulis ke-i	
			}
			
		}
	}

	cout<<maxBPM()+n<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin>>q;
	while(q--){
		memset(adj, 0, sizeof(adj));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		memset(c, 0, sizeof(c));
		solve();
	}

	return 0;
}