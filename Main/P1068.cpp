#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, num[10000], sco[10000], a, b = 0, i, j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>num[i]>>sco[i];
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(sco[i]<sco[j])
            {
                swap(sco[i],sco[j]);
                swap(num[i],num[j]);
            }
            else if(sco[i]==sco[j])
            {
                if(num[j]<num[i])
                    swap(num[j],num[i]);
            }
        }
    m=floor(1.5*m);
    a=sco[m-1];
    for(i=0;i<n;i++)
    {
        if(sco[i]>=a)
            b++;
        else
            break;
    }
    cout<<a<<" "<<b<<endl;
    for(i=0;i<b;i++)
        cout<<num[i]<<" "<<sco[i]<<endl;
    return 0;
} 
