#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n,t;
ull T;
double a;
bool ai[2000010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lf%d",&a,&t);
    	for(int j=1;j<=t;j++)
    	{
    		T=a*j;
    		if(ai[T]==0)  ai[T]=1;
    		else ai[T]=0;
		}
	}
	
	for(int i=1;i<=2000000;i++)
	{
		if(ai[i]==1)
		{
			printf("%d",i);
			return 0;
		} 
	}
    return 0;
}
