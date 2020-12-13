#include<bits/stdc++.h>
using namespace std;
int f1(int k) {return k/100;}
int f2(int k) {return k/10%1000;}
int f3(int k) {return k%1000;}
int main()
{
    int n; 
    bool b = false; 
    cin>>n;
        for(int i=10000;i<=30000;i++)
            if(f1(i)%n==0&&f2(i)%n==0&&f3(i)%n==0)
                {
                    cout<<i<<endl;
                    b=true;
                }
            if(b==false)
                cout<<"No";
        return 0;
}
