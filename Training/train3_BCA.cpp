#include <iostream>
using namespace std;
int n, m;
int c[100][100], a[100][100];
int kq, x[100], k, dem[100];

void duyet(int i){
    if (i > m){
        kq = k;
        return;
    }
    for (int j = 1; j <= n; ++j){
        bool ok = true;
        for (int t = 1; t < i; ++t){
            if (a[i][t] && x[t]==j) ok = false;
        }
        if (ok && c[j][i] && dem[j] + 1 < kq){
            int p_k = k;
            dem[j]++;
            k = max(k, dem[j]);
            x[i] = j;
            duyet(i+1);
            dem[j]--;
            k = p_k;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        while (k--){
            int j;
            cin >> j;
            c[i][j] = 1;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int i, j;
        cin >> i >> j;
        a[i][j] = a[j][i] = 1;
    }
    kq = m;
    duyet(1);
    cout << kq;
    
    return 0;
}
