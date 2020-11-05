#include<bits/stdc++.h>

using namespace std;

#define N 10000
#define MAXINT 2147483647

typedef pair<int, int> ii;

int cha[N], hang[N];

int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

typedef struct _edge {
    int u, v, w;
} edge;

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

int main() {
    int n, m; 
    cin >> n >> m;

    int cost[n+1][m+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];

    vector<edge> edges;
    edge temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp.u = i;
            temp.v = n+j;
            if (cost[i][j] != -1) {
                temp.w = cost[i][j];
            }
            else {
                temp.w = MAXINT;
            }
            edges.push_back(temp);
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i <= n+m; i++) {
        cha[i] = i;
        hang[i] = 0;
    }

    int mst_weight = 0;
    int point = 0;

    vector<ii> joined;

    for (edge &e: edges) {
        if (join(e.u, e.v)) {
            mst_weight += e.w;
            // if (e.w != 0) {
            //     point++;
            //     joined.push_back(e.u, e.w);
            // }
        }
    }

    cout << mst_weight << endl;
    // cout << point << endl;
    // while (!joined.empty()) {
    //     cout << joined.front() << endl;
    // }
    return 0;
}