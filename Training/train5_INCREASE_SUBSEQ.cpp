#include <bits/stdc++.h>

using namespace std;
int a[10000];
int mem[10000];

int lis(int i) {
    if (mem[i] != -1)
        return mem[i];
    int res = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i])
            res = max(res, 1 + lis(j)); 
    }
    mem[i] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(mem, -1, sizeof(mem));
    lis(n-1);
    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, mem[i]);

    cout << result;
    return 0;
}