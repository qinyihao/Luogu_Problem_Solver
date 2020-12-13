#include<bits/stdc++.h>
#define max(u,v) u>v ? u:v
int a[10][10], f[10][10][10][10], x, y, n, k;
int main()
{
	scanf("%d",&n);
	while(scanf("%d%d%d", &x, &y, &k) == 3 && x)
	{
		a[x][y] = k;
	}
	for(int i = 1; i <= n; i++)
	  for(int j = 1; j <= n; j++)
	    for(int k = 1; k <= n; k++)
	      for(int l = 1; l <= n; l++)
	      {
	          int tmp=max(f[i][j][k][l],f[i-1][j][k-1][l]);
	          tmp=max(tmp,f[i][j-1][k][l-1]);
	          tmp=max(tmp,f[i][j-1][k-1][l]);
	          tmp=max(tmp,f[i-1][j][k][l-1]);
	          if(i==k && j==l) f[i][j][k][l]=tmp+a[i][j];
	          else f[i][j][k][l]=tmp+a[i][j]+a[k][l];
		  }
	printf("%d\n",f[n][n][n][n]);
	return 0;
}
