#include <bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(register int i=x;i<=y;++i)
#define go(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
inline int read(){ int x=0,fh=1; char ch=getchar(); while(!isdigit(ch)){ if(ch=='-') fh=-1; ch=getchar(); } while(isdigit(ch)){ x=(x<<1)+(x<<3)+ch-'0'; ch=getchar(); } return x*fh; }

const int maxn=1e5+5;
int a1[maxn],b1[maxn],a2[maxn],b2[maxn],n,m,ans[maxn],c,num[maxn],_num[maxn];
int st[maxn],top,g[maxn],top2;
bool chosen[maxn];
ll tot;
vector<int> g1[maxn],g2[maxn];

bool cmp(int x,int y){
	return b2[x]<b2[y];
}

bool _cmp(int x,int y){
	return b1[x]<b1[y];
}

int main(){
	n=read(),m=read(),c=read();cin>>tot;
	fo(i,1,n) a2[i]=read(),b2[i]=read(),g2[a2[i]].push_back(i);
	fo(i,1,m) a1[i]=read(),b1[i]=read(),g1[a1[i]].push_back(i),g[++top2]=a1[i];
	sort(g+1,g+1+top2);
	top2=unique(g+1,g+1+top2)-g-1;
	memset(ans,-1,sizeof ans);
	fo(i,1,top2){
		int s1=g1[g[i]].size(),s2=g2[g[i]].size();
		if(s2==0){
			tot-=1ll*c*s1;
			continue;
		}
		fo(j,0,s2-1) num[j]=g2[g[i]][j];
		sort(num,num+s2,cmp);
		fo(j,0,s1-1) _num[j]=g1[g[i]][j];
		sort(_num,_num+s1,_cmp);
		if(s1<s2){
			fo(j,0,s1-1) num[j]=num[j+s2-s1];
			s2=s1;
		}
		fo(j,0,s2-1) tot+=b2[num[j]];
		tot-=1ll*(s1-s2)*c;
		int pos2=0; 
		fo(j,0,s1-1){
			while(pos2<s2&&b1[_num[j]]>b2[num[pos2]]) pos2++;
			if(pos2==s2){
				top=0;
				fo(k,0,s2-1) if(!chosen[num[k]]) st[++top]=num[k],tot-=c;
				
				fo(k,j,min(j+top-1,s1-1)) ans[_num[k]]=st[k-j+1];
				break;
			}
			tot+=c;
			chosen[num[pos2]]=1;
			ans[_num[j]]=num[pos2];
			++pos2;
		}
	}
	cout<<tot<<'\n';
	fo(i,1,m-1) printf("%d\n",ans[i]);
	cout<<ans[m];
	return 0;
}
