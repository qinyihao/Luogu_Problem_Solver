#include <bits/stdc++.h>
using namespace std;
int order[100];
string num[100];
int main()
{
     int n, j, tmp;
     cin >> n;     
     for(int i=0;i<n;i++)
     {
        cin>>num[i];
        order[i]=i;
        j=i;
        while(j>0&&num[order[j]]+num[order[j-1]]>num[order[j-1]]+num[order[j]])
        {
          tmp=order[j];
          order[j]=order[j-1];
          order[j-1]=tmp;
          j--;
        }
     }
     for(int i=0;i<n;i++)
        cout<<num[order[i]];
     cout<<endl;
     return 0;
}
