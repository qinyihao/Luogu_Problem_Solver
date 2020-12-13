#include <bits/stdc++.h>
using namespace std;

int n1[10001];
int main()
{
    int n,p,total=0;
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>n1[i];
    for(int i=1;i<n;i++)
    {
       for(int j=1;j<=n-i;j++)
       {
          if(n1[j]>n1[j+1])
          {
            p=n1[j];n1[j]=n1[j+1];n1[j+1]=p;total++;
          }
       }
    }
    cout<<total<<endl;
    return 0;
}
