#include <bits/stdc++.h>
using namespace std;

long long a2,b2,c2,s2;
long long a1,b1,c1,s1;
long long k,ans;

int main()
{
	scanf("%lld:%lld:%lld\n%lld:%lld:%lld",&a1,&b1,&c1,&a2,&b2,&c2);
	s1=a1*3600+b1*60+c1;
	s2=a2*3600+b2*60+c2;
	scanf("%lld",&k);
	ans=k*(s2-s1);
	printf("%lld",ans);
	return 0;
} 
