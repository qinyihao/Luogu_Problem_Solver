#include <bits/stdc++.h>
using namespace std;
const int maxn=1002;
int n;
int f[maxn];
int main()
{
    scanf("%d",&n); 
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i/2;j++)
            f[i]+=f[j];
    printf("%d\n",f[n]);
    return 0;
}
