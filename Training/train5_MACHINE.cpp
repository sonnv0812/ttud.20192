#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int s[2000005], t[2000005];

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> s[i] >> t[i];
    
    int maxs[2000005];
    
    memset(maxs, 0, sizeof(maxs));

    const int M = 2e6 + 5;
    for (int i = 1; i <= n; i++) {
        maxs[t[i]] = max(maxs[t[i]], t[i] - s[i]);
    }
    
    for (int i = 1; i <= M; i++) {
        maxs[i] = max(maxs[i - 1], maxs[i]);
    }

    int ans =  -1;
    for (int i = 1; i <= n; i++) {
        if (maxs[s[i] - 1] > 0) {
            ans = max(ans, maxs[s[i] - 1] + t[i] - s[i]);
        }
    }
    cout << ans << endl;

    return 0;
}