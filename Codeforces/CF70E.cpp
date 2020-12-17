#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define N 205
using namespace std;
int n,k,d[N],dis[N][N],dp[N][N];
int p[N];
int ans[N];
vector<int> v[N];
void aux() {
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int r=1; r<=n; r++)
				dis[i][r]=min(dis[i][r],dis[i][k]+dis[k][r]);
}
void solve(int x,int fa) {
	for(int i=1; i<=n; i++)dp[i][x]=d[dis[i][x]]+k;
	for(int i=0; i<v[x].size(); i++) {
		int to=v[x][i];
		if(to==fa)continue;
		solve(to,x);
		for(int r=1; r<=n; r++)dp[r][x]+=min(dp[p[to]][to],dp[r][to]-k);
	}
	p[x]=1;
	for(int i=2; i<=n; i++)if(dp[p[x]][x]>dp[i][x])p[x]=i;
}
void getans(int x,int fa) {
	for(int i=0; i<v[x].size(); i++) {
		int to=v[x][i];
		if(to==fa)continue;
		ans[to]=(dp[p[to]][to]<dp[ans[x]][to]-k)?p[to]:ans[x];
		getans(to,x);
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<n; i++)scanf("%d",d+i);
	memset(dis,0X3f,sizeof dis);
	for(int i=1; i<=n; i++)dis[i][i]=0;
	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		dis[a][b]=dis[b][a]=1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	aux();
	solve(1,0);
	printf("%d\n",dp[p[1]][1]);
	ans[1]=p[1];
	getans(1,0);
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	return 0;
}
