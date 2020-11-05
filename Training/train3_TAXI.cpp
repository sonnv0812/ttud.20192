#include <iostream>
#include <algorithm>
using namespace std;

int calc(int a[], int *c[], int n){
	int cost = 0;
	for (int i = 0; i < n; i++)
		cost += c[a[i]][a[i]+n];
	for (int i = 0; i < n-1; i++)
		cost += c[a[i]+n][a[i+1]];
	return cost + c[0][a[0]] + c[a[n-1]+n][0];
}

int main(){
    int n;
	cin >> n;
	int **c = new int*[2*n+1];
	for (int i = 0; i < 2 * n + 1; i++)
        c[i] = new int[2 * n + 1];

	for(int i = 0; i < 2*n + 1; i++)
		for(int j = 0; j < 2*n +1; j++)
			cin >> c[i][j];
	
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = i+1;

	int result = 2147483647, cost;

	do {
		// for(int i = 0; i < n; i++)
		// 	cout << a[i] << " ";
		cost = calc(a, c, n);
		result = result > cost ? cost : result;
	}
	while (next_permutation(a, a+n));

	cout << result;

	for (int i = 0; i < 2*n + 1; i++)
        delete(c[i]);
	delete(c);
	return 0;
}