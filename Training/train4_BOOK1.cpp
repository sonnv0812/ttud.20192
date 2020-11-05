#include <bits/stdc++.h>
using namespace std;

int N, m, k; // N <= 200, 1<=k<m<=500
long long x[202]; // <= 10000000

bool check(long long *x, int m, int k, long long maxx) {
    int count_ = 0;
    long long s = 0;
    for (int i = 1; i <= m; i++){
        s += x[i];
        if (s >= maxx) {
            count_ += 1;// += 1 chứ đell dùng ++ nhé clmas
            s = 0;
        }
        if (count_ >= k) return true;
    }
    return false;
}

long long Try(long long *x, int m, int k) {
    long long s = 0;
    for (int i = 1; i <= m; i++)
        s += x[i];
    long long l = 0, r = s;
    while (r > l) {
        long long M = (r+l)/2;
        if (M == l){
            if (check(x, m, k, r))
                return r;
            return l;
        }
        if (check(x,m,k,M)) {
            l = M;
        } else {
            r = M-1;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N; //N cases
    for (int I = 0; I < N; I++) {
        cin >> m >> k;
        for (int i = 1; i <= m; i++) 
            cin >> x[i];
        long long maxx = Try(x,m,k);
        int count_ = 0;
        long long s = 0;
        int t;
        for (t = 1; t <= m; t++){
            cout << x[t] << " ";
            s += x[t];
            if (s >= maxx){
                count_ ++;
                if (count_ == k)
                    break;
                cout << "/" << " ";
                s = 0;
            }
        }
        for (int j = t+1; j <= m; j++)
            cout << x[j] << " ";
        cout << endl;
    }
    return 0;
}
// 2
// 9 3
// 100 200 300 400 500 600 700 800 900
// 5 4
// 100 100 100 100 100
// output
// 100 200 300 400 500  / 600 700  / 800 900 
// 100  / 100  / 100  / 100 100 
