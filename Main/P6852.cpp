#include <bits/stdc++.h>
using namespace std;
const int maxn=500010;
int n,m,x,y,v,Lok[maxn],Rok[maxn],Lban[maxn],Rban[maxn],pre[maxn],ans[maxn];
bool findans;
set<int>st;
template <typename T>
inline void read(T &ans)
{
    ans=0;
    char ch=getchar(),f=1;
    for(;ch<'0'||ch>'9';ch=getchar())
    if(ch=='-')f=0;
    for(;ch>='0'&&ch<='9';ch=getchar())
    ans=(((ans<<2)+ans)<<1)+(ch^'0');
    ans=f?ans:-ans;
}
void write(int x)
{
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	read(n);read(m);
	for(int i=0;i<=n;i++)st.insert(i);
	for(int i=0;i<=n+1;i++)Lok[i]=0,Rok[i]=n,Lban[i]=n+1,Rban[i]=-1;
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);read(v);
		if(v)Lok[v-1]=max(Lok[v-1],x),Rok[v-1]=min(Rok[v-1],y),
		Lban[v]=min(Lban[v],x),Rban[v]=max(Rban[v],y);
		else pre[x]++,pre[y+1]--;
	}
	for(int i=n;i>=0;i--)Lok[i]=max(Lok[i],Lok[i+1]),Rok[i]=min(Rok[i],Rok[i+1]);
	for(int i=0;i<=n;i++)
	{
		pre[i]+=pre[i-1];
		if(Lok[0]<=i&&i<=Rok[0]&&pre[i]==0){ans[i]=0;st.erase(i);break;}
	}
	for(int i=1;i<=n;i++)
	{
		set<int>::iterator t=st.lower_bound(Lok[i]);
		if(t!=st.end()&&*t<=Rok[i]&&(Lban[i]>*t||*t>Rban[i]))ans[*t]=i,st.erase(t);
		else if(Rban[i]!=-1)
		{
			t=st.lower_bound(Rban[i]+1);
			if(t!=st.end()&&*t<=Rok[i])ans[*t]=i,st.erase(t);
		}
	}
	if(!st.empty()){printf("-1\n");return 0;}
	for(int i=0;i<=n;i++)write(ans[i]),putchar(' ');printf("\n");
	return 0;
}
