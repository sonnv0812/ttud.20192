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
int ans, giaithuaa;
int giaithua(int a){
    if(a == 0) return 1;
    return a * giaithua(a-1);
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
            int an = 1;
            Fr(i, 1, k) {
                an *= giaithua(L[i]);
            }
            ans += an;
        }
        return;
    }
    Fr(i,1,k)
    {
        if(w[i]+d[u]<=q)
        {
            w[i]+=d[u];
            L[i]++;
            dfs(u+1);//xet nguoi tiep theo
            w[i]-=d[u];
            L[i]--;
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&k,&q);
    giaithuaa = giaithua(k);
    Fr(i,1,n) scanf("%d",&d[i]);
    ans=0;
    dfs(1);
    ans /= giaithuaa;
    printf("%d",ans % mod);
    return 0;
}