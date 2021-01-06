#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,tot,N,f[3005],s[3005][2],S[3005],mx[3005],mn[3005];
int fa[3005][16],dep[3005];
long long dp[3005][1505];
int find(int p){
    return f[p]==p?p:f[p]=find(f[p]);
}
struct node{
    int u,v,w;
    friend bool operator<(node u,node v){
        return u.w<v.w;
    }
}c[2250005];

int LCA(int u,int v){
    if(dep[u]<dep[v])
        swap(u,v);
    for(int i=12;i>=0;i--)
        if((1<<i)<=dep[u]-dep[v])
            u=fa[u][i];
    if(u==v)
        return u;
    for(int i=12;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    return fa[u][0];
}
void dfn(int p){
    for(int i=1;fa[fa[p][i-1]][i-1];i++)
        fa[p][i]=fa[fa[p][i-1]][i-1];
    if(!s[p][0]&&!s[p][1])
        return;
    dep[s[p][0]]=dep[p]+1;
    dfn(s[p][0]);
    dep[s[p][1]]=dep[p]+1;
    dfn(s[p][1]);
}
void dfs(int p){
    if(fa[p][0]==0||mn[fa[p][0]]>mx[p])
        dp[p][1]=1;
    if(!s[p][0]&&!s[p][1]){
        S[p]=1;
        return;
    }
    dfs(s[p][0]);
    dfs(s[p][1]);
    S[p]+=S[s[p][0]]+S[s[p][1]];
    for(int i=1;i<=S[s[p][0]];i++)
        for(int j=1;j<=S[s[p][1]];j++)
            dp[p][i+j]=(dp[p][i+j]+dp[s[p][0]][i]*dp[s[p][1]][j]%Mod)%Mod;
    // cout<<mx[p]<<" "<<mn[p]<<" "<<S[p]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    N=n;
    for(int i=1;i<=n;i++){
        f[i]=i;
        for(int j=1,u;j<=n;j++){
            cin>>u;
            if(i<j)
                c[++tot]={i,j,u};
        }
    }
    sort(c+1,c+tot+1);
    for(int i=1;i<=tot;i++){
        if(find(c[i].u)!=find(c[i].v)){
            N++;
            f[N]=N;
            mn[N]=c[i].w;
            fa[find(c[i].u)][0]=N;
            s[N][0]=find(c[i].u);
            fa[find(c[i].v)][0]=N;
            s[N][1]=find(c[i].v);
            f[find(c[i].u)]=N;
            f[find(c[i].v)]=N;
        }
    }
    dfn(N);
    for(int i=1;i<=tot;i++){
        int lca=LCA(c[i].u,c[i].v);
        while(lca!=N){
            mx[lca]=c[i].w;
            lca=fa[lca][0];
        }
    }
    dfs(N);
    for(int i=1;i<=n;i++)
        cout<<dp[N][i]<<" ";
    return 0;
}
