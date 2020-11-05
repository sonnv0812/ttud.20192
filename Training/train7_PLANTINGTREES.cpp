#include<bits/stdc++.h>

using namespace std;

int a[100009];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int res = 1, j = 1;
    for (int i = n-1; i >= 0; i--)  
    {
        a[i] += j++;
        res = max(a[i], res);
    }
    res++;
    printf("%d\n", res);

}