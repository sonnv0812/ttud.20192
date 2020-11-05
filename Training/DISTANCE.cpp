#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int c[n+1][n+1];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    
    int m;
    cin >> m;
    int road[m+1];
    int cost = 0;
    for (int i = 1; i <= m; i++) {
        cin >> road[i];
    }

    for (int i = 2; i <= m; i++)
        cost += c[road[i-1]][road[i]];

    cout << cost;

    return 0;
}