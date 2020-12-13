#include <bits/stdc++.h>
using namespace std;

long long a[100][100];
int b[100][100];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};

int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	b[x][y]=1;
	for(int i=0; i<8; i++)
		if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
			b[x+dx[i]][y+dy[i]]=1;
	int k=0;
	while(!b[k][0] && k<=n)	a[k++][0]=1;
	int l=0;
	while(!b[0][l] && l<=m)	a[0][l++]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(b[i][j])	a[i][j]=0;
			else a[i][j]=a[i][j-1]+a[i-1][j];
	cout << a[n][m];
	return 0;
} 
