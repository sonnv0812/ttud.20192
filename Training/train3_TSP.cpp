#include <iostream>
using namespace std;
 
int maxC = 2147483647;
int C[30][30];  
int X[30];  
int T[30];  
bool FREE[30];  
int minSpending;  
int M, N;
 
void input() {
    cin >> N >> M;   
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            C[i][j] = 0;
 
    int i, j;
    for (int k = 1; k <= M; k++) {
        cin >> i >> j;
        cin >> C[i][j];
    }
}
 
void init() {
    for (int i = 0; i <= N; i++)
        FREE[i] = true;
    FREE[1] = false;  
    X[1] = 1;  
    T[1] = 0; 
    minSpending = 2147483647;
}
 
void tim(int i) {
    for (int j = 2; j <= N; j++) {
        if (FREE[j] && C[X[i-1]][j] != 0) {
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j];  
            if (T[i] < minSpending) {
                FREE[j] = false;  
                if(i == N) {
                    if (C[X[N]][1] != 0 && T[N] + C[X[N]][1]  < minSpending) {
                        minSpending = T[N] + C[X[N]][1];
                    }
                }
                else tim(i+1);  
                FREE[j] = true; 
            }
        }
    }
}
 
int main() {
    input();
    init();
    tim(2);
    cout << minSpending;
    return 0;
}