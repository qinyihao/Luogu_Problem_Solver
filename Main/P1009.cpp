#include <bits/stdc++.h>
using namespace std;
int a[5000], f[5000];
int i, j, k, n;
void add(int num, int t)
{   
        f[t] = f[t]+num;
        f[t+1] = f[t+1] + f[t] / 10000;
        f[t] = f[t] % 10000;
}
int main()
{  
  cin >> n;
  a[1] = 1;k=1;
  for(i=1;i<=n;i++)
  {
        for(j=1;j<=k;j++)
            a[j]=a[j]*i;
        for(j=1;j<=k;j++)
     {
        a[j+1]=a[j+1]+a[j]/10000;
        a[j]=a[j]%10000;
     }
     if(a[k+1]>0) k++;
     for(int j=1;j<=k;j++)
        add(a[j],j); 
  }
  cout << f[k];
  for(j = k-1; j >= 1; j--)
  printf("%04d", f[j]);
  return 0; 
}
