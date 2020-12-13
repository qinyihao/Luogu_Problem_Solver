#include <bits/stdc++.h>
using namespace std;

struct stu {
	int num,c,m,e,sum;
} st[310];

bool cmp(stu a,stu b) {
	if(a.sum==b.sum) if(a.c==b.c) return a.num<b.num;
		else return a.c>b.c;
	else return a.sum>b.sum;
}

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) st[i].num=i,cin>>st[i].c>>st[i].m>>st[i].e,st[i].sum=st[i].c+st[i].m+st[i].e;
	sort(st+1,st+1+n,cmp);
	for(int i=1; i<=5; i++) cout<<st[i].num<<' '<<st[i].sum<<endl;
	return 0;
}
