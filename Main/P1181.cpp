#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[100005],s,sum;
int main()
{
    cin>>n>>m;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=n; i>=1; i--)
    {
        if (s+a[i]<=m)s+=a[i];
        else
        {
            sum++;
            s=a[i];
        }
    }
    sum++;
    cout<<sum;
    return 0;
}
