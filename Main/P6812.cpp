#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,m,l,r,k,op,t[1000010],b[1000010];
int lowbit(int i){
    return i&(-i);
}
int check(long long x){
    return (x>=0);
}
void upd(long long *tt,int i,long long x){
    while(i<=n){
        tt[i]+=x;
        i+=lowbit(i);
    }
}
long long sum(long long *tt,int x){
    long long ans=0;
    while(x){
        ans+=tt[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(0);
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>a[i];
        upd(t,i,check(a[i]-a[i-1]));
        b[i]=a[i]-a[i-1];
    }
    for(register int i=1;i<=m;++i){
        cin>>op;
        if(op==1){
            cin>>l>>r>>k;
            upd(t,l,check(b[l]+k)-check(b[l]));
            b[l]+=k;
            upd(t,r+1,check(b[r+1]-k)-check(b[r+1]));
            b[r+1]-=k;
        }
        else{
            cin>>l>>r;
            if(sum(t,r)-sum(t,l)==r-l){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
}
