#include<bits/stdc++.h>
using namespace std;
void find(int n)
{
    int t=n;
    int m[18]={0},i=0,j=0;
    while(n!=0)
    {
        m[i++]=n%2;
        n/=2;                              
    }
    int maxxx=0;
    for(j=i;j>=0;j--)
        if(m[j])maxxx=j;
    for(j=i;j>=0;j--)
    if(m[j])if(j==1)
        if(m[0]!=0)cout<<"2+";
        else cout<<'2';
    else
    {
        cout<<"2(";
        if(j>2)find(j);
        else cout<<j;cout<<")";
        if(j!=maxxx)cout<<"+";
    }
}

int main()
{
    int n;
    cin>>n;
    find(n);
    return 0;
} 
