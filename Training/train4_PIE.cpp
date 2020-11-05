#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    queue<double> ans;
    while (testcase != 0) {
        int n, f;
        cin >> n >> f;
        int r[n];
        for (int i = 0; i < n; i++)
            cin >> r[i];

        sort(r, r+n);
        double low = 0, high = 4e8, mid;
        for (int it = 0; it < 100; it++) {
            mid = (low + high) / 2;
            int cont = 0;
            for (int i = n-1; i >= 0 && cont <= f; i--) {
                cont += (int) floor(PI * r[i] * r[i] / mid);
            }
            // for (int i = 0; i < n; i++) {

            // }
            if (cont > f)
                low = mid;
            else
                high = mid;
        }
        ans.push(low);
        testcase--;
    } 
    
    while (!ans.empty()) {
        printf("%0.6f\n", ans.front());
        ans.pop();
    }

    return 0;
}