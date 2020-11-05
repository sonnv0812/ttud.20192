#include<bits/stdc++.h>
using namespace std;
#define Fr(i, a, b) for(int i = a; i <= b; i++)
#define For(i, a, b) for(int i = a; i < b; i++)

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int N = 1111;
int n, m, c[N][N];
int cnt, mark1[N], mark2[N], par[N];
bool d[N], dd[N];
vector<iii> ve;

int anc(int u)  {
    if(u != par[u]) 
        par[u] = anc(par[u]);
    return par[u];
}

void dfs(int u, int p) {
    if(p == 0) {
        mark1[u] = cnt;
        d[u] = 1;
        Fr(i, 1, m) 
            if(c[u][i] == 0 && !dd[i]) {
                dfs(i, 1);
            }
    }
    else {
        mark2[u] = cnt;
        dd[u] = 1;
        Fr(i, 1, n) 
            if(c[i][u] == 0 && !d[i]) {
                dfs(i, 0);
            }
    }
}

int main() {
    cin >> n >> m;
    Fr(i, 1, n) 
        Fr(j, 1, m) 
            cin >> c[i][j];

    //Find and build new graph
    Fr(i, 1, n) 
        if(!d[i]) {
            cnt++;
            dfs(i, 0);
        }
    Fr(i, 1, n) {
        Fr(j, 1, m) 
            if(c[i][j] > 0 && mark1[i] != mark2[j]) {
                ve.push_back(iii(c[i][j], ii(mark1[i], mark2[j])));
            }
    }
    //Kruskal with disjoin set
    int ans = 0;
    Fr(i, 1, cnt) 
        par[i] = i;
    sort(ve.begin(), ve.end());
    for(int i = 0; i < ve.size(); i++) {
        int u = ve[i].se.fi;
        int v = ve[i].se.se;
        u = anc(u);
        v = anc(v);
        if ( u != v) {
            ans += ve[i].fi;
            par[u] = v;
        }
    }
    cout << ans << endl;
    return 0;
}
