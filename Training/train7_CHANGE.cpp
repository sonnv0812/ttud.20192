  
#include<bits/stdc++.h>

using namespace std;

int a[6] = {1, 5, 10, 50, 100, 500};
int main(){
    int n;
    cin >> n;
    int ans =0;
    n = 1000- n;
    for (int i = 5; i >= 0; i--)
    {
        ans += n/a[i];
        n = n % a[i];
    }
    cout << ans;
    return 0;
    
}