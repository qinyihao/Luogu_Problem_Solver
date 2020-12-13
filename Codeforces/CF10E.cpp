#include <bits/stdc++.h>
using namespace std;

int a[401],n,i,j,k,p,c,t,S=-1;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			p=a[i]-1,c=1,t=a[j];
			for(k=0;k<=j;k++) c+=p/a[k],t+=p/a[k]*a[k],p%=a[k];
			for(p=t,k=0;k<n;k++) c-=p/a[k],p%=a[k];
			if(c<0&&(S<0||S>t))S=t;
		}
	cout<<S;
  return 0;
}
