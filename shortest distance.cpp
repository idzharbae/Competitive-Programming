vector<int> bfs (int s) {
    vector<int> dist(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
            if (dist[u] == -1)
                dist[u] = dist[v]+1, q.push(u);
    }
    return d;
}

const int inf = 1e9;
vector<int> dijkstra(int s) {
    priority_queue< pair<int, int> > q;
    q.push({0, s});
    vector<int> d(n, inf);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.top(); q.pop();
        for (auto e : adj[v]) {
            int u = e.first, w = e.second;
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
    return d;
}
