#include <bits/stdc++.h>
using namespace std;

int n,zn,m,cp;
bool b,c;

int main()
{
	cin>>n;
	m=(n-2)/3+1;
	if((n-2)%3==0) b=1,n-=1;
	if(n%6==0) c=1;
	cp=m+1-b;
	int dt=cp+n-1-(((n-2)/3+1)/2*3);
	if(b) cout<<dt+1<<"\n";
	else cout<<((n%6)?dt-1:dt)<<"\n";
	for(int i=1;i<n;i++,cp++){
		cout<<((b&&i==n-1)?3:2)<<" "<<(i-1)/3+1<<" "<<cp-(((i-1)/3+1)/2*3);
		if(i!=n-1) cout<<"\n";
	}
	if(b) cout<<" "<<dt<<"\n2 "<<dt<<" "<<dt+1<<"\n";
	else cout<<"\n";
	if(b) dt+=3;
	cout<<dt-m-1+c<<" ";
	for(int i=1;i+m<dt+c;i++)
	{
		cout<<i+m-b<<" ";
	}
	cout<<"\n";
	return 0;
}
