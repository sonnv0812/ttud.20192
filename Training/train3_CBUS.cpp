#include <iostream>
using namespace std;
 
int visited[30], x[30];
int n, seat;
int c, road_min, cost;
int minSpending;
int road[30][30];
 
void init() {
    for (int i = 1; i <= 2*n ; i++)
        visited[i] = 0;
    minSpending = 2147483647;
    cost = 0;
    c = 0;
}
 
int UCV(int i) {
    if (i <= n)
        return (!visited[i] && c < seat);
    else
        return (visited[i-n] && !visited[i]);
}
 
void Try(int k) {
    for (int i = 1; i <= 2*n; i++) 
        if (UCV(i)) {
            if (i <= n) 
                c++;
            else
                c--;
            visited[i] = 1;
            x[k] = i;
            cost = cost + road[x[k-1]][x[k]];
            if (k == 2*n) {
                if (cost + road[x[2*n]][0] < minSpending)
                    minSpending = cost + road[x[2*n]][0];
            }
            else {
                int g = cost + (2*n + 1 - k)*road_min;
                if (g < minSpending)
                    Try(k+1);
            }
            visited[i] = 0;
            cost = cost - road[x[k-1]][i];
            if (i <= n)
                c--;
            else
                c++;
        }
}
 
int main() {
    cin >> n >> seat;
    road_min = 2147483647;
    for (int i = 0; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++) {
            cin >> road[i][j];  
            if (road[i][j] != 0 && road[i][j] < road_min)
                road_min = road[i][j];
        }
    init();
    Try(1);
    cout << minSpending;
 
    return 0;
}