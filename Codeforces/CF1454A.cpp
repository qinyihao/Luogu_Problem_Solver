#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll; 
const int M=1e2+10;
const int inf=0x3f3f3f3f;
int n;
int a[M];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			for(int i=n;i>=1;i--)
				printf("%d%c",i,i==1?'\n':' ');
		}
		else
		{
			int cnt=1;
			for(int i=n;i>=1;i--)
				a[cnt++]=i;
			a[n/2+1]=1;
			a[n]=n/2+1;
			for(int i=1;i<=n;i++)
				printf("%d%c",a[i],i==n?'\n':' ');
		}
	}
  return 0;
}
