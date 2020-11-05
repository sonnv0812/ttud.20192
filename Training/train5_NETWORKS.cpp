#include<bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
int n,k,m;
vector<ii> adj[10011];
int f[10011];
int ans = __INT32_MAX__;
void dfs(int x, int p, int depth){
    if (depth == k)
    {
        ans = min(ans, f[x]);
        return;
    }
    for(auto i: adj[x]){
        int y = i.first;
        if (y == p)
        {
            continue;
        }
        
        f[y] = i.second + f[x];
        dfs(y,x, depth+1);
    }
}

int main(){
    cin >> n >> k >> m;
    while (m--)
    {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back(ii(y,w));
        adj[y].push_back(ii(x,w));
    }
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
        dfs(i,0,0);
    }
    
    cout << ans;
}