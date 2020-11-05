#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
int n, m, s, t;
vector<ii> adj[100001];

int dijkstra(int s, int t){
    vector<int> dis(n+1, INT32_MAX), mark(n+1, 0);
    dis[s] = 0;
    for(int repeat = n; repeat --; ) {
        int u = -1;
        for (int i = 1; i <= n; i++) {
            if (!mark[i] && (u == -1 || dis[i] < dis[u])) {
                u = i;
            }
        }
        if(u == t) return dis[t];
        if (u == -1) {
            break;
        }
        mark[u] = 1;
        for(auto e: adj[u]) {
            int v = e.first, w = e.second;
            dis[v] = min(dis[v], dis[u] + w); 
        }
    }
    return  -1;
}


int main() {
    // freopen("SHORTEST PATH PRIORITY QUEUE.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(v, w));
    }
    cin >> s >> t;
    cout << dijkstra(s, t);
}