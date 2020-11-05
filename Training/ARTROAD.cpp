#include <bits/stdc++.h>
using namespace std;

int n, k;
int l[5001], r[5001], pic[5001];

void bubbleSort() {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i; j < n; j++) {
            if (pic[j] > pic[i]) {
                swap(pic[j], pic[i]);
                swap(l[j], l[i]);
                swap(r[j], r[i]);
            }
        }
    }
}

// void in() {
//     for (int i = 0; i < n; i++) {
//         cout << pic[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++) {
//         cout << l[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++) {
//         cout << r[i] << " ";
//     }
//     cout << endl;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    k = k - 2;
    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i];
        pic[i] = r[i] - l[i] + 1;
    }
    bubbleSort();
    int mark[5001];
    for (int i = 1; i <= n; i++)
        mark[i] = 0;
    
    int result = 0;

    // in();
    int temp = 0;
    while (k > 0) {
        if (temp == n)
            break;
        int temp1 = result;
        for (int i = l[temp]; i <= r[temp]; i++)
            if (mark[i] == 0) {
                mark[i] = 1;
                result++;
            }
        if (result == temp1)
            k++;
        temp++;
        k--;
    }
    cout << result;
    return 0;
}