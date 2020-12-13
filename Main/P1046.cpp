#include <bits/stdc++.h>  
using namespace std;
int main()  
{
    int a;
    double b=0;
    cin >>a;
    for (float i=1;i<=1000000;i++)
    {
        b+=1/i;   
        if (b>a) 
        {
            cout <<i;
            return 0;
        }  
    }  
}  
