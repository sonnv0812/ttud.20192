#include <iostream>
using namespace std;
 
int a[100000];
int m, k, n, count = 0;

int cnk(int a, int b){
    if (a == 0 || a == b) return 1;
    if (a == 1) return b;
    return cnk(a - 1, b - 1) + cnk(a, b - 1);
}

void backtrack(int i) { 
    for(int j = a[i-1] + 1; j <= n-m+i; j++) { 
        a[i] = j; 
        if(i == m){
            count++;
            // for(int z = 1; z <= m; z++)
            //     cout << a[z] << " ";
            // cout << endl;
            if(count == k){
                for(int t = 1; t <= m; t++)
                    cout << a[t] << " ";
                break;
            }
        }
        else
            backtrack(i+1); 
    }
    return;
}

void toHop(){ 
    if(m >= 1 && m <= n) {
        a[0] = 0; 
        backtrack(1);
    }
    else {
        cout << "-1" << endl;
    }
}
 
int main(){
    cin >> n >> m >> k ;
    if (k > cnk(m, n)){
        cout << "-1";
        return 0;
    }
    toHop();
    return 0;
}