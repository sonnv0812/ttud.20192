#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100001];


int main(){
    // freopen("LCOUNT.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            cnt++;
        }
    }
    cout << cnt;
}