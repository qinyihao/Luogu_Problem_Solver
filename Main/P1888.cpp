#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int a[3],t,g;
    cin >> a[0] >> a[1] >> a[2];
    for(int i=0;i<=2;i++)
        for(int j=i+1;j<=2;j++)
            if(a[i]>a[j])
            {t=a[i];a[i]=a[j];a[j]=t;}
    g=gcd(a[0],a[2]);
    cout << a[0]/g << '/' << a[2]/g << endl;
    return 0;
}
