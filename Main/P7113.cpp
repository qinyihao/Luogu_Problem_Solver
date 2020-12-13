#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
unsigned long long n,m,x,y;
struct node
{
    unsigned long long ba;
    unsigned long long dad;
    unsigned long long sl;
    unsigned long long son[10];
};
node t[100005];
bool b[100005];
__int128 a[100005][3];
inline void output(__int128 x)
{
    if(x>9)
        output(x/10);
    putchar(x%10+'0');
}
__int128 gcd(__int128 a,__int128 b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void chuli(__int128 aa,__int128 bb,__int128 cc)
{
    if(a[cc][1]==0) 
    {
        a[cc][1]=aa;
        a[cc][2]=bb;
    }
    else
    {
        __int128 lmx=aa*a[cc][2]+bb*a[cc][1];
        __int128 lym=bb*a[cc][2];
        __int128 cz=gcd(lmx,lym);
        a[cc][1]=lmx/cz;
        a[cc][2]=lym/cz;
    }
}
void dfs(__int128 xx)
{
    if(t[xx].sl==0) return;
    __int128 za=a[xx][1],zb=a[xx][2]*t[xx].sl;
    __int128 f=gcd(za,zb);
    za/=f;zb/=f;
    for(int i=1;i<=t[xx].sl;i++)
    {
        chuli(za,zb,t[xx].son[i]);
        t[t[xx].son[i]].dad++;
        if(t[t[xx].son[i]].dad==t[t[xx].son[i]].ba)dfs(t[xx].son[i]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        if(i<=m) a[i][1]=a[i][2]=1;
        scanf("%d",&x);
        t[i].sl=x;
        for(int j=1;j<=x;j++)
        {
          scanf("%d",&y);
          t[i].son[j]=y;
          t[y].ba++;    
        }
        if(x==0) b[i]=true;
    }
    for(int i=1;i<=m;i++)
    {
        dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]) 
        {
            output(a[i][1]);
            cout<<' ';
            output(a[i][2]);
            cout<<endl;
        }
    }
}
