#include<bits/stdc++.h>
using namespace std;
double n,m,s,ans;
int k;
int right(double u){
	double sum=0,v=1;
	for(int i=1;i<=k;i++){
		v*=(1+u);
		sum+=(m/v);
	}
	if(sum==n) return 0;
	if(sum>n) return 1;
	else return -1;
}
int main(){
	scanf("%lf%lf%d",&n,&m,&k);
	double l=0,r=800,mid;
	while(r-l>=0.0001){
		mid=(l+r)/2;
		if(!right(mid)) break;
		if(right(mid)==1) l=mid;
		else r=mid;
	}
	printf("%.1lf",mid*100);
	return 0;
}
