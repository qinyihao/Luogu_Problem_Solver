#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
inline ll read() {
    register ll s=0,f=1;
    register char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-')f=-f; ch=getchar();}
    while(isdigit(ch)) {s=(s<<1)+(s<<3)+(ch^48); ch=getchar();}
    return s*f;
}
void dfs(ll n,ll k) {
    if(n==0) return;
    ll temp=1ull<<(n-1);
    if(k<temp) {cout<<"0"; dfs(n-1,k);}
    else {cout<<"1"; dfs(n-1,temp-k-1+temp);}
}
int main() {
    ll n=read(),k=read();
    dfs(n,k);
    return 0;
}
