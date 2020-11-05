#include<bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<ii, int>
#define h second
#define width first.first
#define length first.second
int n;
int ans[100];
vector<iii> gach;

void cal(vector<int> f, int dem){
    for (int i = 0; i < f.size(); i++)
    {
        f[i] = gach[i].h;
        for (int j = 0; j < i; j++)
        {
            if (gach[j].width > gach[i].width && gach[j].length > gach[i].length)
            {
                f[i] = max(f[i], f[j] + gach[i].h);
            }
        }
    }
    ans[dem] = *max_element(f.begin(), f.end());
};
int main(){
    int dem = 1;
    cin >> n;
    while (n)
    {
        gach.clear();
        for (int i = 0; i < n; i++)
        {
            int m,n,p;
            cin >> m >> n >> p;
            gach.push_back(iii(ii(min(n,p),max(n,p)),m));
            gach.push_back(iii(ii(min(m,p),max(m,p)),n));
            gach.push_back(iii(ii(min(n,m),max(n,m)),p));
        }
        sort(gach.begin(),gach.end());
        reverse(gach.begin(), gach.end());
        vector<int> f(gach.size());
        cal(f,dem++);
        cin >> n;
    }
    for (int i = 1; i < dem; i++)
    {
        cout << "Case " << i << ": maximum height = " << ans[i] << endl;
    }
}