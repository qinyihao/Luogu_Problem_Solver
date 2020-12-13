#include <bits/stdc++.h>
using namespace std;

int hh,i,p,ans=0,k,now,next[10005],n,a[10005],head=0;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++)
        next[i]=i+1;
    a[n]=1e30;
    k=0;
    while (k!=n-1)
    {
        now=a[head]+a[next[head]];
        i=p=next[head];
        hh=a[next[i]]<now?next[i]:i;
        while (k!=n-2&&a[i]<now)  {p=i;i=next[i];}
        next[p]=next[head];
        next[next[head]]=i;
        a[next[head]]=now;
        head=hh;
        ans+=now;
        k++;
    }
    printf("%d",ans);
    return 0;
}
