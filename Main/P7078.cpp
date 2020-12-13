#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
    static int f;static char c;
    for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
    for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
    static int q[64];int cnt=0;
    if(x==0)return pc('0'),void();
    if(x<0)pc('-'),x=-x;
    while(x)q[cnt++]=x%10,x/=10;
    while(cnt--)pc(q[cnt]+'0');
}
const int maxn=1000005;
int n,a[maxn],q0[maxn],q1[maxn],q2[maxn],A[maxn],B[maxn],in[maxn],cp[maxn],c2;
int hp[maxn];
void solve2(int st){
    for(int i=1;i<=n;++i)hp[i]=false;
    int key=a[q2[0]],p=1;hp[q2[0]]=true;
    while(p<c2&&a[q2[p]]==key)hp[q2[p]]=true,++p;
    int e=p,MN=0;p=1;while(!hp[p])++p;
    for(int i=c2-1;i>=e;--i){
        A[st]=q2[i];
        if(MN){
            B[st]=MN;
            if(((a[q2[i]]-=a[MN])<key)||q2[i]<p)
                MN=q2[i];
            else{
                MN=0;hp[q2[i]]=true;
            }
        }
        else{
            B[st]=p;hp[p]=false;++p;
            while(p<=n&&!hp[p])++p;
            a[MN=q2[i]]-=key;
        }
        ++st;
    }
    if(MN&&a[MN]==key){
        hp[p=MN]=true;MN=0;
    }
    if(MN){
        for(int i=n;i>=1;--i)if(hp[i]){
            A[st]=i;B[st]=MN;++st;MN=i;
        }
    }
    else{
        int o=0;
        for(int i=n;i>=1;--i)if(hp[i]){
            o^=1;
            if(o){
                if(MN){
                    A[st]=i,B[st]=MN;++st;
                }
                MN=i;
            }
            else{
                A[st]=MN;B[st]=i;++st;
            }
        }
    }
}
void solve(void){
    for(int i=1;i<=n;++i)cp[i]=a[i],in[i]=0;
    int f0=0,b0=0,f1=n,b1=n;
    for(int i=1;i<=n;++i)q0[b0++]=i;
    for(int i=1;i<n;++i){
        int mx=-1,mxp=0;
        if(f0<b0&&(a[q0[b0-1]]>mx||(a[q0[b0-1]]==mx&&q0[b0-1]>mxp)))mx=a[mxp=q0[b0-1]];
        if(f1<b1&&(a[q1[b1-1]]>mx||(a[q1[b1-1]]==mx&&q1[b1-1]>mxp)))mx=a[mxp=q1[b1-1]];
        int mn=1000000001,mnp=n+1;
        if(f0<b0&&(a[q0[f0]]<mn||(a[q0[f0]]==mn&&q0[f0]<mnp)))mn=a[mnp=q0[f0]];
        if(f1<b1&&(a[q1[f1]]<mn||(a[q1[f1]]==mn&&q1[f1]<mnp)))mn=a[mnp=q1[f1]];
        if(a[mxp]<a[mnp]*2){
            int _l=f0,_r=f1;c2=0;
            while(_l<b0||_r<b1){
                if(_r>=b1||(_l<b0&&(a[q0[_l]]<a[q1[_r]]||(a[q0[_l]]==a[q1[_r]]&&q0[_l]<q1[_r])))){
                    q2[c2++]=q0[_l++];
                }
                else{
                    q2[c2++]=q1[_r++];
                }
            }
            solve2(i);
            break;
        }
        A[i]=mxp;B[i]=mnp;
        if(f0<b0&&q0[f0]==mnp)++f0;else ++f1;
        if(f0<b0&&q0[b0-1]==mxp)--b0;else --b1;
        a[mxp]-=a[mnp];q1[--f1]=mxp;
    }
    int no=n;
    for(int i=n-1;i>=1;--i){
        ++in[B[i]];
        if(in[A[i]])
            while(no>i)--in[B[--no]];
    }
    --no;
    for(int i=1;i<=n;++i)a[i]=cp[i];
    write(n-no),pc('\n');
}
int main(){
    int T;read(T),read(n);
    for(int i=1;i<=n;++i)read(a[i]);
    solve();--T;
    while(T--){
        int k;read(k);
        while(k--){
            int x,y;
            read(x),read(y);
            a[x]=y;
        }
        solve();
    }
    return 0;
}
