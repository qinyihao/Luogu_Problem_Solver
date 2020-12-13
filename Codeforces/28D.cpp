#include <bits/stdc++.h>
using namespace std;

const int maxn=100005,INF=0x3f3f3f3f;
int n,f[maxn],prt[maxn],st[maxn],cot=0;map<int,int>fro[maxn];

int main() {
	scanf("%d",&n);
	int i,v,c,l,r,t,ans=0;
	f[0]=-INF;
	for(i=1;i<=n;i++) {
		scanf("%d%d%d%d",&v,&c,&l,&r),f[i]=-INF;
		t=c+l+r;if(l==0)f[i]=v;
		if(t<=100000&&fro[t].count(l))prt[i]=fro[t][l],f[i]=f[prt[i]]+v;
		if(t<=100000&&f[i]>=0){
			if(!fro[t].count(l+c)||f[fro[t][l+c]]<f[i])fro[t][l+c]=i;
		}
		if(r==0&&f[i]>f[ans])ans=i;
	}
	while(ans)st[++cot]=ans,ans=prt[ans];
	printf("%d\n",cot);
	while(cot)printf("%d ",st[cot--]);
	return 0; 
}
