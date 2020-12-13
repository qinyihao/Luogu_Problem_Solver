#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1024;
int l[MAXN],r[MAXN];
LL sum[MAXN],lt[MAXN],num[MAXN*MAXN];
int n,m,tot,siz;
char c;
inline int read(){
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    int p=0;
    while(c>='0'&&c<='9') p=p*10+c-'0',c=getchar();
    return p;
}
inline void push_down(int k){
    if(!lt[k]) return;
    for(int i=l[k];i<=r[k];i++) num[i]+=lt[k];
    lt[k]=0;
}
int main(){
    n=read();m=read();
    siz=int(sqrt(n));
    l[tot]=1;
    for(int i=1,a;i<=n;i++){
        num[i]=read();
        r[tot]=i;
        sum[tot]+=num[i];
        a++;
        if(a==siz&&i<n) l[++tot]=i+1,a=0;
    }
    for(int k=0,a,b,c,d;k<m;k++){
        a=read();b=read();c=read();
        if(a==1){
            d=read();
            for(int i=0;i<=tot;i++){
                if(l[i]>=b&&r[i]<=c) sum[i]+=(r[i]-l[i]+1)*d,lt[i]+=d;
                else if(l[i]<=b&&r[i]>=b){
                    sum[i]+=(r[i]-b+1)*d;
                    push_down(i);
                    for(int j=b;j<=r[i];j++) num[j]+=d;
                }
                else if(l[i]<=c&&r[i]>=c){
                    sum[i]+=(c-l[i]+1)*d;
                    push_down(i);
                    for(int j=l[i];j<=c;j++) num[j]+=d;
                }
            }
        }
        else{
            LL ans=0;
            for(int i=0;i<=tot;i++){
                if(l[i]>=b&&r[i]<=c) ans+=sum[i];
                else if(l[i]<=b&&r[i]>=b){
                    push_down(i);
                    for(int j=b;j<=r[i];j++) ans+=num[j];
                }
                else if(l[i]<=c&&r[i]>=c){
                    push_down(i);
                    for(int j=l[i];j<=c;j++) ans+=num[j];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
