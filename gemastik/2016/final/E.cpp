#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;


bool visited[50000];
vector<int> adj[50000];
int root;

int pumpsWithDistance(int dist){

    vector<pair<int,int> > st;
    int ans = 0;
    st.push_back({root,0});
    while(st.size() > 0){
        pair<int,int> b = st.back(); st.pop_back();
        int u = b.first, t = b.second;
        visited[u] = true;
        if(t == dist)
            ans++;
        else if(adj[u].size() == 1 and u != root){
            ans++;
            continue;
        }
        cout<<u<<" "<<t<<endl;
        for(auto v : adj[u]){
            int nxt = t+1;
            if(nxt > 2*dist)
                nxt = 0;
            if(!visited[v]){
                st.push_back({v,nxt});
            }
        }
    }
    return max(ans,1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q; cin>>q;
    while(q--){
        int n,k; cin>>n>>k;
        cout<<"n = "<<n<<" k = "<<k<<endl;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++)
            adj[i].clear();
        for(int i = 0; i < n-1; i++){
            int x,y; cin>>x>>y;
            x--; y--;
            adj[x].push_back(y);
            if(adj[x].size() == 1)
                root = x;
            adj[y].push_back(x);
            if(adj[y].size() == 1)
                root = y;
        }

        for(int i = 0; i <= 10; i++){
            cout<<"dist = "<<i<<" pumps = \n"<<pumpsWithDistance(i)<<endl;
        }

    }
    

    return 0;
}
