#include <bits/stdc++.h>
using namespace std;
int n,a,p;
int main()
{
	cin>>n;
	for(int i=0;i<n*n;i+=a)
	{
		cin>>a;
		for(int j=1;j<=a;j++)
		{
			if(p) cout<<"1";
			else cout<<"0";
			if((i+j)%n==0) cout<<endl;
		}
		p=!p;
	}
	return 0;
}
