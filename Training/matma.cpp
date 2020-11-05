#include <iostream>
#include <string>
using namespace std;

int main(){
    string m, k;
    cin >> m >> k;
	int mlen = m.length(), klen = k.length(), i, j;
	char newk[mlen], mahoa[mlen];

	for(i = 0, j = 0; i < mlen; ++i, ++j){
		if(j == klen)
		    j = 0;
		newk[i] = k[j];	
	}
	newk[i] = '\0';
	for(i = 0; i < mlen; ++i)
	    mahoa[i]= ((m[i] + newk[i]) % 26) + 'A';
	mahoa[i] = '\0';

	cout << "Ma goc: " << m; 
	cout << "\nK: " << k;
	cout << "\nmahoa: " << mahoa;
}