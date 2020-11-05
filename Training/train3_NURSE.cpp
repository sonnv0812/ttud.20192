#include <iostream>
using namespace std;

int n, count = 0, k1, k2;
char TKB[200];

void Try(int Tam, int k);

int main() {
	cin >> n >> k1 >> k2;
	Try(0, 0);
	if(count == 0)
		cout << "-1";
	else 
        cout << count;
        
    return 0;
}

void Try(int Tam, int k){	
	if(k == n){
		if((Tam >= k1 && Tam <= k2) || Tam == 0){
			count++;			
		}
		return;
	}
	if(Tam >= k1 || k == 0){
		Try(0, k + 1);
	}
		
	if(Tam < k2){
		Try(Tam + 1, k + 1);
	}		
}