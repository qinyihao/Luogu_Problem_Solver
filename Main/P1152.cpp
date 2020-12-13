#include <bits/stdc++.h>
using namespace std;
int n,x,a[10001]={0},f[10001]={0};
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x=abs(a[i]-a[i-1]);
        if(x>=1&&x<=n)f[x]=1;
    }
    
    for(int i=1;i<n;i++)if(!f[i])
    {
        cout<<"Not jolly";
        return 0;
    }
    cout<<"Jolly";
    return 0;
}
