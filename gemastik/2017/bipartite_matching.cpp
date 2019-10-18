#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
using namespace std;

// N is number of Perusahaan  
// and N is total soal by all penulis
#define N 50
#define M 2500
// A DFS based recursive function  
// that returns true if a matching 
// for vertex u is possible 
bool bpm(bool bpGraph[M][N], int u, 
         bool seen[], int matchR[]) 
{ 
    // Try every job one by one 
    for (int v = 0; v < N; v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (bpGraph[u][v] && !seen[v]) 
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
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// Returns maximum number 
// of matching from M to N 
int maxBPM(bool bpGraph[M][N]) 
{ 
    // An array to keep track of the  
    // applicants assigned to jobs.  
    // The value of matchR[i] is the  
    // applicant number assigned to job i, 
    // the value -1 indicates nobody is 
    // assigned. 
    int matchR[N]; 
  
    // Initially all jobs are available 
    memset(matchR, -1, sizeof(matchR)); 
  
    // Count of jobs assigned to applicants 
    int result = 0;  
    for (int u = 0; u < M; u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
  
        // Find if the applicant 'u' can get a job 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int n,q;
	cin>>q;
	while(q--){
		int soal[N];
		int perus[N][N];
		int m[N];
		// banyak penulis
		bool bpArr[M][N] = {0};
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			// banyak soal per penulis
			cin>>soal[i];
			soal[i]-=1;
		}
		for (int i = 0; i < n; ++i)
		{
			// banyak perusahaan
			cin>>m[i];
			for (int j = 0; j < m[i]; ++j)
			{
				// angka perusahaan
				cin>>perus[i][j];
				perus[i][j]--;
			}

			for (int j = 0; j < soal[i]; ++j)
			{
				for (int k = 0; k < m[i]; ++k)
				{
					bpArr[i*50 + j][perus[i][k]] = 1;
				}
			}
		}
		cout<<n+maxBPM(bpArr)<<endl;

	}

	return 0;
}