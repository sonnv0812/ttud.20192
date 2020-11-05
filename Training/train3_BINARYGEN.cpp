#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string input;
    cin >> n >> input;
    // cout << input.length() << "  " << input[2];

    for(int i = n-1; i >= 0; i--){
        if(input[i] == '1'){
            if(i == 0){
                cout << "-1";
                return 0;
            }
            else continue;
        }

        input[i] = '1';
        for(int j = i+1; j < n; j++){
            input[j] = '0';
        }
        break;
    }
    cout << input;
	return 0;
}
