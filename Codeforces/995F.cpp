#include<bits/stdc++.h>
#define maxn 3009
#define mod 1000000007
#define LL long long
using namespace std;
struct data{int nex,to;}e[maxn];
int head[maxn],edge=0,f[maxn][maxn],n,D;
inline void add(int from,int to){
  e[++edge]=(data){head[from],to};
  head[from]=edge;
}
void dfs(int x){
#define v e[i].to
  for(int i=head[x];i;i=e[i].nex) dfs(v);
  for(int j=1;j<=n;j++){
    f[x][j]=1;
    for(int i=head[x];i;i=e[i].nex)
      f[x][j]=(LL)f[x][j]*f[v][j]%mod,f[v][j+1]=(f[v][j+1]+f[v][j])%mod;
  }

}
int inv(int x){
  if(x==1) return 1;
  return mod-(LL)mod/x*inv(mod%x)%mod;
}
int main(){
  scanf("%d%d",&n,&D);
  for(int i=2,x;i<=n;i++)
    scanf("%d",&x),add(x,i);
  dfs(1);
  for(int j=1;j<=n;j++) f[1][j]=(f[1][j-1]+f[1][j])%mod;
  if(D<=n) printf("%d",f[1][D]),exit(0);
  int ans=0;
  for(int i=1;i<=n;i++){
    int A=1,B=1;
    for(int j=0;j<=n;j++)
      if(j!=i) A=(LL)A*(D-j)%mod,B=(LL)B*(i-j+mod)%mod;
    ans=((LL)f[1][i]*A%mod*inv(B)+ans)%mod;
  }
  printf("%d",ans);
  return 0;
}
