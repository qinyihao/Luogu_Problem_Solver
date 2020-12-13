#include<bits/stdc++.h>
using namespace std;
int read(){
	register char ch;
	register bool f=false;
	while(!isdigit(ch=getchar()))if(ch=='-')f=true;
	register int x=ch^'0';
	while(isdigit(ch=getchar()))x=x*10+(ch^'0');
	return f?-x:x;
}
long long dp[3][1009][1009];
//0:从左;1:从下;2:从上;
int val[1009][1009];
inline long long ut_max(long long a,long long b){
	return a>b?a:b;
}
inline long long ut_max(long long a,long long b,long long c){
	return ut_max(a,ut_max(b,c));
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	register int n=read(),m=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			val[i][j]=read();
	dp[0][1][1]=val[1][1];
	for(int i=2;i<=n;++i)dp[0][1][i]=-1e12;
	for(register int j=1;j<=m;++j){
		dp[1][j][n]=dp[2][j][1]=-1e12;
		if(j>1)for(register int i=1;i<=n;++i)
		dp[0][j][i]=ut_max(dp[0][j-1][i],dp[1][j-1][i],dp[2][j-1][i])+val[i][j];
		for(register int i=n-1;i;--i)
		dp[1][j][i]=ut_max(dp[1][j][i+1],dp[0][j][i+1])+val[i][j];
		for(register int i=2;i<=n;++i)
		dp[2][j][i]=ut_max(dp[2][j][i-1],dp[0][j][i-1])+val[i][j];
	}
	//for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("dp[%d,%d]:%lld,%lld,%lld %d\n",i,j,dp[0][j][i],dp[1][j][i],dp[2][j][i],val[i][j]);
	printf("%lld\n",ut_max(dp[0][m][n],dp[2][m][n]));
	fflush(stdout);
	return 0;
}
