#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=1e9+7,N=2e5,M=100;
int a[maxn];
int sum[maxn];
long long c[maxn][110]={0};
void init(){
	for(int i=0;i<=N;i++)c[i][0]=1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(i>=j){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				c[i][j]%=mod;
			}
		}
	}
}
int main(){
	init();
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]-a[i]<=k)j++;
			sum[i]=j-i-1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(sum[i]>=m-1){
				ans+=c[sum[i]][m-1];
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
