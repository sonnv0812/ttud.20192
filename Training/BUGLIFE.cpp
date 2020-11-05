#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int scenarios, bugs, interactions;
int color[2001];
int ans;
vector<int> couple[2001], co[2];
bool dfs(int u, int mau = 1)
{
    color[u] = mau;
    // cout << u << " " << mau << endl;
    co[2 - mau].push_back(u);
    for (auto &&v : couple[u])
    {
        if (!color[v] && !dfs(v, 3 - color[u]))
        {
            return 0;
        }
        if (color[v] == mau)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    // freopen("buglife.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> scenarios;
    for (int i = 0; i < scenarios; i++)
    {
        ans = 0;
        cin >> bugs >> interactions;
        for (int j = 0; j < interactions; j++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            couple[temp1].push_back(temp2);
            couple[temp2].push_back(temp1);
        }

        cout << "Scenario #" << i + 1 << ":" << endl;
        for (int j = 1; j <= bugs; j++)
        {
            if (color[j])
            {
                // cout << 1 << endl;
                continue;
            }
            if (!couple[j].size())
            {
                // cout << 2 << " " << couple[j].size() << endl;
                color[j] = 1;
                continue;
            }
            if(!dfs(j)) {
                // cout << 3 << endl;
                ans = 1;
                break;
            }
        }

        if (ans)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }

        memset(color, 0, sizeof(color));
        for (int j = 0; j < 2001; j++)
        {
            couple[j].clear();
        }
    }
}