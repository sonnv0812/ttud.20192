#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    int temp = testcase;
    queue<long long int> result;

    while (testcase > 0) {
        long long int n;
        cin >> n;
        
        long long int x[n], y[n];

        for (long long int i = 0; i < n; i++) 
            cin >> x[i];
        for (long long int i = 0; i < n; i++) 
            cin >> y[i];

        long long int ans = 0;
        sort(x, x+n);
        sort(y, y+n);

        for (long long int i = 0; i < n; i++)
            ans += x[i]*y[n-i-1];

        result.push(ans);
        testcase--;
    }

    while (temp > 0) {
        cout << "Case #" << ++testcase << ": " << result.front() << endl;
        result.pop();
        temp--;
    }

    return 0;
}