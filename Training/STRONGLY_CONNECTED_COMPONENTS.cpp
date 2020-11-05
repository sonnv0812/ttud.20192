#include<bits/stdc++.h>

using namespace std;

int n,m ;
int cnt =0, num[100010], inS[100010], low[100010];
stack<int> st;
vector<int> f[100010];
int ans = 0;

void dfs(int x){
    // if(inS[x]) return;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << inS[i+1] << " ";
    // }
    // cout << endl;
    num[x] = ++cnt;
    st.push(x);
    inS[x] = 1;
    low[x] = num[x];
    // cout << cnt << endl;
    for(int y: f[x]){
        // cout << "y: " << y << " x: " << x << endl;
        // cout << "num[y]: " << num[y] << " inS[y]: " << inS[y] <<endl;
        if(num[y] != 0 && !inS[y]) continue;// canh cheo
        if(num[y] == 0){// canh xuoi
            // cout << "low["<< x << "] " << low[x] << endl; 
            dfs(y);
            low[x] = min(low[x], low[y]);
        }else //canh nguoc
        {
            low[x] = min(low[x], num[y]);
            // cout << "low["<<x<<"] " << low[x] << endl; 
        }
    }
    if (num[x] == low[x])
    {
        while(1){
            int temp = st.top();
            st.pop();
            inS[temp] = 0;
            // cout << temp << " " << x << endl;
            if (temp == x)
            {
                ans++;
                break;
            }
        }
    }
    
}
int main(){
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("\n%d %d", &u, &v);
        f[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++)
    {   
        if (!num[i])
        {
            dfs(i);
        }
    }
    printf("%d", ans);
}