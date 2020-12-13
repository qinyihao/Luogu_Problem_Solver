#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a=1,b=1,c,i,n;
    cin>>c;
    if(c==0)cout<<"0.00";
    else {
        if(c%2==1)n=c/2+1;
        if(c%2==0)n=c/2;
        if(c==1||c==2)cout<<"1";
        else
        {
            for(i=2; i<=n; i++)
            {
                a=a+b;
                b=b+a;
            }
            if(c%2==1)cout<<a<<".00";
            if(c%2==0)cout<<b<<".00";
        }
    }
    return 0;
}
