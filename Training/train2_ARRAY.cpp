#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int equal0 = 0, am = 0;
    for(int i = 0; i < n; i++)
        if (a[i] < 0)
            am++;
        else if (a[i] == 0)
            equal0++;

    int temp;
    int tam[2];
    cout << "1 ";
    for (int i = 0; i < n; i++)
        if(a[i] < 0) {
            cout << a[i] << endl;
            temp = i;
            break;
        }
    if (am % 2 == 0 && am != 2 || am >= 3) {
        cout << "2";
        int check = 0;
        for (int i = temp+1; i < n; i++) {
            if (a[i] < 0) {
                tam[check++] = i;
                cout << " " << a[i];
            }
            if (check == 2)
                break;
        }
        equal0 = n-3;
        cout << endl;
    }
    else {
        cout << "1";
        int check = 0;
        for (int i = 0; i < n; i++) {
            if (i == temp)
                continue;
            if (a[i] > 0){
                check++;
                tam[0] = tam[1] = i;
                cout << " " << a[i];
                break;
            }
        }
        equal0 = n-2;
        cout << endl;
    }
    cout << equal0;
    for (int i = 0; i < n; i++) {
        if (i == temp || i == tam[0] || i == tam[1])
            continue;
        cout << " " << a[i];
    }

    return 0;
}