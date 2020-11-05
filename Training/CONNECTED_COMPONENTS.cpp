#include<bits/stdc++.h>

using namespace std;
vector<int> adj[100000];
vector<int> comp_id(100000, -1);
int n,m ;
void find_components(int cur_comp, int v){
    if (comp_id[v] != -1)
    {
        return;
    }
    
    comp_id[v] = cur_comp;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        find_components(cur_comp, u);
    }
    
}
int main(){
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout << "sss";
    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if(comp_id[i] == - 1){
            find_components(components,i);
            components++;
        }
    }
    cout << components;
}