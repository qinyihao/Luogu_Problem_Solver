#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=2e5+100;
const int maxn=1e6;
const int MAXL=sqrt(1e9)+1;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n,k,a[1010];
void solve()
{
    n=read();   k=read();
   for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=n;i>1;i--)
    {
        while(a[i]<=k)
        {
            ans++;
            a[i]+=a[1];
        }
        ans--;
    }
    printf("%d\n",ans);

}

int main()
{
    int T;
    scanf("%d",&T);
    int tt=0;
    while(T--)

    {
        solve();
    }

    return 0;

}
