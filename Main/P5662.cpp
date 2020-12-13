#include<cstdio>
#include<cstring>
#define N 105
int f[N*N],last[N],weight[N],value[N],n,m,s;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("souvenir.in","r",stdin);
	//freopen("souvenir.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<=m;++i) scanf("%d",&last[i]);
	for (int i=2;i<=n;++i)
	{
		for (int j=1;j<=m;++j) weight[j]=last[j],scanf("%d",&last[j]),value[j]=last[j]-weight[j];
		memset(f,0,sizeof f);
		for (int j=1;j<=m;++j)
		    for (int k=1;k<=s;++k)
		        if (k>=weight[j])
		            f[k]=max(f[k],f[k-weight[j]]+value[j]);
		s+=f[s];
	}
	printf("%d",s);
    //fclose(stdin);fclose(stdout);
	return 0;
}
