#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a+n);
    int left, right;
    
    int ans = 0;
    for (int i = 0; i < n - 2; i++) { 
        left = i + 1; 
        right = n - 1; 
        while (left < right) { 
            if (a[i] + a[left] + a[right] == m) { 
                ans++; 
                left++;
            } 
            else if (a[i] + a[left] + a[right] < m) 
                left++; 
            else 
                right--; 
        } 
    } 

    cout << ans;
    return 0;
}