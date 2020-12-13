#include<bits/stdc++.h>
using namespace std;
struct data
{
	int s,q;
}
a[40001];
bool cmp(data u,data v)
{
	return u.s<v.s;
}
int main()
{
	int l, m, x, y, tot = 0, sum = 0;
	scanf("%d%d", &l, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		a[i*2-1].q=0;
		a[i*2-1].s=x;
		a[i*2].q=1;
		a[i*2].s=y;
	}
	sort(a+1,a+m*2+1,cmp);
	sum+=a[1].s+l-a[2*m].s;
	for(int i=1;i<=2*m;i++)
	{
		if(!tot&&i>1) sum+=a[i].s-a[i-1].s-1; 
		if(!a[i].q) tot++;
		else tot--;
	}
	printf("%d",sum);
	return 0;
}
