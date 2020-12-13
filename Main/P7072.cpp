#include<bits/stdc++.h>
using namespace std;
int read(){
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar()))x=x*10+(ch^'0');
	return x;
}
const int N=609,M=1024;
int zkw[N<<2];
inline void update(int x){
	for(++zkw[x+=M];x>>=1;zkw[x]=zkw[x<<1]+zkw[x<<1|1]);
}
inline int query(int num){
	register int pos=1;
	while(pos<M){
		if(zkw[pos<<1]>=num)pos<<=1;
		else num-=zkw[pos<<1],pos=pos<<1|1;
	}return pos-M;
}
int main(){
	//freopen("live.in","r",stdin);
	//freopen("live.out","w",stdout);
	register int n=read(),w=read();
	for(register int i=1;i<=n;++i){
		update(601-read());
		printf("%d ",601-query(max(i*w/100,1)));
	}fflush(stdout);
	return 0;
}
