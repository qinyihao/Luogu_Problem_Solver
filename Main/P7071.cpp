#include<bits/stdc++.h>
using namespace std;
int read(){
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar()))x=x*10+(ch^'0');
	return x;
}
int main(){
//	freopen("power.in","r",stdin);
//	freopen("power.out","w",stdout);
	int n=read();
	if(n&1)puts("-1");
	else{
		stack<int>tmp;
		while(n)tmp.push(n&-n),n&=n-1;
		while(!tmp.empty())printf("%d ",tmp.top()),tmp.pop();
	}
//  fflush(stdout);
	return 0;
}
