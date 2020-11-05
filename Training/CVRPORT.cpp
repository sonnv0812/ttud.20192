#include<bits/stdc++.h>
using namespace std;
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ll,int> lii;
const int mod=1e9+7;
const int oo = INT_MAX-1;
const int N = 101;
int n,q,k,d[N],w[N],mark[N], L[N];
int ans, best,tong;
int a[N][N];
vector<int> route[N];

void Try(int i, int size, int src, int k){
    if (k == size)
    {
        tong += a[src][0];
        best = min(best, tong);
        return;
    }
    For(j,0,size) {
        if(!mark[j])
        {
            mark[j] = 1;
            int temp = tong;
            tong += a[src][route[i][j]];
            Try(i, size, route[i][j], k+1);
            tong = temp;
            mark[j] = 0;
        }
    }
}
int TSP(){
    int sum =0;
    Fr(i,1,k) {
        tong = 0;
        best = INT32_MAX;
        Try(i, route[i].size(), 0, 0);
        sum += best;
    }
    return sum;
}
void dfs(int u)
{
    if(u>n)
    {
        bool ok=true;
        Fr(i,1,k) if(w[i]==0)
        {
            ok=false;
            break;
        }
        if(ok) {
            ans = min(ans, TSP());
        }
        return;
    }
    Fr(i,1,k)
    {
        if(w[i]+d[u]<=q)
        {
            w[i]+=d[u];
            route[i].push_back(u);
            dfs(u+1);
            w[i]-=d[u];
            route[i].pop_back();
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d %d",&n,&k,&q);
    Fr(i,1,n) scanf("%d",&d[i]);
    Fr(i, 0,n) Fr(j,0,n) cin >> a[i][j];
    ans=INT32_MAX;
    dfs(1);
    printf("%d",ans);
    return 0;
}