#include <bits/stdc++.h>
using namespace std;
char c[1005];
int main()
{
    int zimu;
    int sign=1;
    for(int i=0;i<=1000;i++)c[i]=-1;    
    cin>>c;
    int a=0;
    int num=0;
    int i=1;
    int save=0;
    int fuhao=1;
    if((c[0]>='a')&&(c[0]<='z'))
        {
            zimu=0;
            a++;
        }
    if((c[0]>='0')&&(c[0]<='9'))
        {
            int h=c[0];
            h=h-'0';
            save=h;
        }
    if(c[0]=='-')
        {
        fuhao=-1;
        }
    while(1)
    {
        if(c[i+1]==-1)
        {
        num=num+save*sign*fuhao;
        break;
        }
        if(c[i]=='+')
        {
        num=num+save*sign*fuhao;
        save=0;
        fuhao=1;
        }
        if(c[i]=='-')
        {
        num=num+save*sign*fuhao;
        save=0;
        fuhao=-1;
        }
        if(c[i]=='=')
        {
        num=num+save*sign*fuhao;
        save=0;
        fuhao=1;
        sign=-1;
        }
        if((c[i]>='0')&&(c[i]<='9'))
        {
            int h;
            h=c[i]-'0';
            save=save*10+h;
        }
        if((c[i]>='a')&&(c[i]<='z'))
        {
            zimu=i;
            if(save==0)save=1;
            a=a+save*sign*fuhao;
            save=0;
        }
        i++;
    }
    double ans;
    double chushu=num;
    double beichushu=a;
    ans=chushu/beichushu;
    ans=ans*(-1);
    if(ans==-0)ans=0;
    cout<<c[zimu]<<"=";
    cout << fixed << setprecision(3) << ans << endl;
    
    return 0;
}
