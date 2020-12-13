#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a[4];
int main()
{
	int q;
	scanf("%lld", &q);
	for(int i = 1; i <= q; i++)
	{
		scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3]);
		sort(a, a+4);
		if(a[0]+a[3]!=a[1]+a[2])
		{
		    printf("0\n");
		    continue;
		}
		if(a[0]==a[1]&&a[1]==a[2])
		{
		    printf("1\n");
		    continue;
		}
		if(a[0]==a[1]&&a[2]==a[3])
		{
		    printf("4\n");
		    continue;
		}
		printf("8\n");
		continue;
	}
	return 0;
} 
