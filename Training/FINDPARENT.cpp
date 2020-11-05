#include<bits/stdc++.h>

using namespace std;

int T;
vector<int> adj[100001];
int parent[100001];

void dfs(int par){
    for (int a : adj[par])
    {
        if (parent[a])
        {
            continue;
        }
        parent[a] = par;
        dfs(a);
    }
}

int main(){
    cin >> T;
    for (int i = 1; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    for (int i = 1; i < T; i++)
    {
        cout << parent[i+1] << " ";
    }
}