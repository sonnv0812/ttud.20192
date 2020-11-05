#include <stdio.h>

long long int wood(long long int a[], long long int n, long long int h) {
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
        if (a[i] > h)
            sum += a[i] - h;
    return sum;
}

int main() {
    long long int n, m;
    scanf("%lld %lld", &n, &m);

    long long int w[n], maxWood = 0;;
    for (long long int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
        if (w[i] > maxWood)
            maxWood = w[i];
    }   
    // cout << maxWood;

    long long int ans = 0;
    long long int low = 0, high = maxWood, mid, temp;
    while (high >= low) {
        mid = (high + low) / 2;
        temp = wood(w, n, mid);
        if (temp > m) {
            low = mid + 1;
            if (mid > ans)
                ans = mid;
        }
        else if (temp < m)
            high = mid - 1;
        else {
            ans = mid;
            break;
        }
    }
    
    printf("%lld", ans);

    return 0;
}