#include <iostream>
#include <algorithm>
using namespace std;

int n, b;
int result = 0, weight = 0, quality = 0;
 
// void bubbleSort(int arr[], int arr1[], int n) {
//     int i, j;
//     bool haveSwap = false;
//     for (i = 0; i < n-1; i++) {
//         haveSwap = false;
//         for (j = 0; j < n-i-1; j++) {
//             if (arr[j] < arr[j+1]) {
//                 swap(arr[j], arr[j+1]);
//                 swap(arr1[j], arr1[j+1]);
//                 haveSwap = true; 
//             }
//         }
//         if(haveSwap == false) {
//             break;
//         }
//     }
// }

void knapsac(int a[], int c[], int k) {
    for (int i = 0; i <= 1; i++) {
        if (i == 1) {
            weight += a[k];
            quality += c[k];
        }
        if (weight <= b) {
            if (k == n-1) {
                if (result < quality)
                    result = quality;
            }
            else
                knapsac(a, c, k+1);
        }
        if (i == 1) {
            weight -= a[k];
            quality -= c[k];
        }
    }
}

int main() {
    cin >> n >> b;
    int a[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];

    // bubbleSort(c, a, n);
    knapsac(a, c, 0);
    cout << result;
    return 0;
}