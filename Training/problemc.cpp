#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, min, max;
    cin >> n >> min >> max;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int count = 0;
    int sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum >= min && sum <= max)
                count++;
        }
    }

    cout << count;

    return 0;
}