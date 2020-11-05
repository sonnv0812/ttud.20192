#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int doixuoi[n], doinguoc[n];
    int tlx[n], tln[n];
    doixuoi[0] = 0;
    doinguoc[0] = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1])
            doixuoi[i] = 1;
        else
            doinguoc[i] = 0;
    }
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[i+1])
            doinguoc[n-i-1] = 1;
        else
            doinguoc[n-i-1] = 0;
    }

    tlx[0] = 0;
    tln[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1])
            tlx[i] = 1;
        else
            tlx[i] = 0;
    }
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < arr[i+1])
            tln[n-i-1] = 1;
        else
            tln[n-i-1] = 0;
    }

    int count = 0;
    int count1 = 0;
    vector<int> doi;
    vector<int> tl;
    for (int i = 0; i < n; i++) {
        if (doixuoi[i] == 1)
            count++;
        else {
            if (count != 0)
                doi.push_back(count);
            count = 0;
        }

        if (tlx[i] == 1)
            count1++;
        else {
            if (count1 != 0)
                tl.push_back(count1);
            count1 = 0;
        }
    }
    count = 0;
    count1 = 0;
    for (int i = 0; i < n; i++) {
        if (doinguoc[i] == 1)
            count++;
        else {
            if (count != 0)
                doi.push_back(count);
            count = 0;
        }

        if (tln[i] == 1)
            count1++;
        else {
            if (count1 != 0)
                tl.push_back(count1);
            count1 = 0;
        }
    }

    sort(doi.begin(), doi.end());
    sort(tl.begin(), tl.end());
    cout << doi.at(0) << " " << tl.at(0);
    return 0;
}