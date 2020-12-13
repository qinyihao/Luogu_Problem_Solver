#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i=192;i<=329;i++)
    {
        int p=i,j=i<<1,k=i*3,t=0;
        while (p) t|=1<<p%10-1,p/=10;
        while (j) t|=1<<j%10-1,j/=10;
        while (k) t|=1<<k%10-1,k/=10;
        if ((t&511) == 511) printf("%d %d %d\n",i,i<<1,i*3);
    }
    return 0;
}
