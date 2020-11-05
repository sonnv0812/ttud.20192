#include<bits/stdc++.h>
 
using namespace std;
void proc(int i, long long int w, int c)
{
    int so_cach[]= {1,1,1,1,2,1,2,1,1,3};
    int so_to[]= {0,1,1,1,2,1,2,2,2,3};
    
    long long cach=1,to=0;
    int d;
    while (c > 0 && w > 0)
    {
        c--;
        d = w%10;
        w /= 10;
        to += so_to[d];
        cach *= so_cach[d];
    }
    if (w == 0)
    {
        cout << to << " " << cach << endl;
        return;
    }
    if (w%5 == 0)
    {
        to += w/5;
    }
    else if (w%5 == 1)
    {
        to += w/5 + 1;
        if (w != 1)
            cach *= 2;
    }
    else if (w%5 == 2)
    {
        to += w/5 +1;
    }
    else if (w%5 == 3)
    {
        to += w/5 +1;
    }
    else if (w%5 == 4)
    {
        to += w/5 +2;
        if (w != 4)
            cach*= 3;
        else
            cach*= 2;
    }
    cout << to << " " << cach << endl;
}
 
 
int main(){
    long long int w;
    int testcase,c;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> w >> c;
        if(w %1000 != 0) {
            cout << 0 << endl;
            continue;
        }
 
        proc(i,w/1000,c);
    }
    return 0;
}