#include<bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
int c[5010];
int main()
{
	int n, l;
	scanf("%d%d", &l, &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		b[i] = min(a[i], l - a[i] + 1);
		c[i] = max(a[i], l - a[i] + 1);
	}
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	printf("%d %d", b[n], c[n]);
	return 0;
}
