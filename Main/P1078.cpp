#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(register int i = (a),i##_end_ = (b); i <= i##_end_; ++i)
inline int read()
{
    char c = getchar();register int fg = 1, sum = 0;
    while(c < '0' || c > '9')
    {
        if(c == '-')fg = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        sum =sum * 10 + c - '0';
        c = getchar();
    }
    return fg * sum;
} 
const int maxn = 4010;
int n, k, m, s, t;
int c[maxn], a[maxn][maxn];
int be[maxn], ne[maxn], to[maxn], e, w[maxn];
#define inf 0x3f3f3f3f
void add(int x,int y,int z)
{
    to[++e] = y;
    ne[e] = be[x];
    be[x] = e;
    w[e] = z;
    to[++e] = x;
    ne[e] = be[y];
    be[y] = e;
    w[e] = z;
}
int ans = inf;
int vis_c[maxn],vis[maxn],cnt;
void dfs(int x,int y,int step)
{
    if(step > ans) return ;
    if(x == y)ans = min(ans,step);
    for(int i = be[x]; i;i = ne[i])
    {
        int v = to[i];
        int flag = 0;
        REP(j,1,k)if(vis_c[j] && a[j][c[v]]){flag = 1;break;}
        if(!vis[v] && !vis_c[c[v]] && !flag)
        {
            vis[v] = 1;vis_c[c[v]] = 1;
            dfs(v,y,step+w[i]);
            vis[v] = 0,vis_c[c[v]] = 0;
        }
    }
}
int main()
{
    n = read(), k = read(), m = read(), s = read(), t = read();
    REP(i,1,n)c[i] = read();
    REP(i,1,k)
        REP(j,1,k)
            a[i][j] = read();
    REP(i,1,m)
    {
        int x,y,z;
        x = read(), y = read(), z = read();
        add(x,y,z);
    }
    vis[t] = 1, vis_c[c[t]] = 1;
    dfs(t,s,0);
    printf("%d\n",ans == inf ? -1 : ans);
    return 0;
}
