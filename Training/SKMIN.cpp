#include <bits/stdc++.h>
using namespace std;

char name[10002];
int k;
char namePerfect[10002];
int temp;

void rename(char s[], int n, int i) {
    if ((k - i) == strlen(s) - n - 1) {
        for (int z = n+1; z < strlen(s); z++)
            namePerfect[i++] = s[z];
        return;
    }        
    int max = (int) s[n];
    temp = n;
    for (int j = n+1; j <= strlen(s) - k+i; j++)
        if ((int) s[j] > max) {
            temp = j;
            max = (int) s[j];
        }
    namePerfect[i] = s[temp];
    if (i != k-1)
        rename(s, temp+1, i+1);
    return;
}

int main() {  
    cin >> name;
    cin >> k;
    rename(name, 0, 0);
    cout << namePerfect;
    return 0;
}