#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[m+1];
    for(int i = 1; i <= m; i++)
        cin >> arr[i];

    for(int i = m; i > 0; i--){
        if(arr[i] == n-m+i){
            if(i == 1){
                cout << "-1";
                return 0;
            }
            else continue;
        }
        arr[i] = arr[i]+1;
        for(int j = i; j <= m; j++)
            arr[j] = arr[i] + j - i;
        break;
    }
    for(int i = 1; i <= m; i++)
        cout << arr[i] << " ";
    return 0;
}