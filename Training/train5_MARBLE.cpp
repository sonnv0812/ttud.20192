#include<bits/stdc++.h>

using namespace std;

int W,H,N;
int f[1000][1000], mark[1000][1000];

int main(){
    cin  >> W >> H >> N;
    for (int i = 1; i <= N; i++)
    {
        int a,b;
        cin >> a >> b;
        mark[a][b] = 1;
    }
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            f[i][j] = i * j;
            if (mark[i][j])
            {
                f[i][j] = 0;
            }
            for (int k = 1; k < i; k++)
            {
                f[i][j] = min(f[i][j], f[k][j]+ f[i-k][j]);
            }
            
            for (int k = 1; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k]+ f[i][j-k]);
            }
        }
    }
    cout << f[W][H];
}