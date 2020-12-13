#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a1,a2=-274,f=1,g=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1;
        if(a1>=a2)
        {
            f++;
            if(f>g)g=f;
        }
        else    
            f=1;
        a2=a1;
    }
    cout<<g;
    return 0;
}
