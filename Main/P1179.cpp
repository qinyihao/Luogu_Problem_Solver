#include <bits/stdc++.h>
using namespace std;
int sz(int n)
{
    int tmp,x=0;
    for (;n!=0;)
    {
        tmp=n%10;
        if (tmp==2) x++;
        n/=10;
    }
    return x;
}
int main()
{
    int aaa,baa,xxx=0;
    cin>>aaa>>baa;
    for (;aaa<=baa;aaa++)
    {
        xxx+=sz(aaa);
    }
    cout<<xxx;
    return 0;
}
