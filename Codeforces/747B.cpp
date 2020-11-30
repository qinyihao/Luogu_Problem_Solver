#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;
    string s; cin>>s;

    int a=0,c=0,g=0,t=0,h=0;
    if(n%4!=0){
        return cout<<"==="<<endl,0;
    }
    for(int i=0; i<n;i++)
    {
        if(s[i]=='A')a++;
        if(s[i]=='C')c++;
        if(s[i]=='G')g++;
        if(s[i]=='T')t++;
        if(s[i]=='?')h++;
    }
    //cout<<a<<" "<<c<<" "<<g<<" "<<t<<endl;
    int mx = max(a,max(c,max(g,t)));
    //cout<<mx<<endl;
    int p=(mx-a)+(mx-c)+(mx-g)+(mx-t);
    //cout<<h<<" "<<p<<endl;
    if(h<p || ((h-p)%4!=0))return cout<<"==="<<endl,0;
    a = (mx-a)+((h-p)/4);
    c = (mx-c)+((h-p)/4);
    g = (mx-g)+((h-p)/4);
    t = (mx-t)+((h-p)/4);
    //cout<<a<<" "<<c<<" "<<g<<" "<<t<<endl;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='?'){
            if(a>0)s[i]='A';
            a--;
        }
        if(s[i]=='?'){
            if(c>0)s[i]='C';
            c--;
        }
        if(s[i]=='?'){
            if(g>0)s[i]='G';
            g--;
        }
        if(s[i]=='?'){
            if(t>0)s[i]='T';
            t--;
        }
    }
    cout<<s<<endl;

    return 0;
}
