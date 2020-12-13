#include<bits/stdc++.h>
using namespace std;
int n;long long ans[200005];
struct nod{
	long long p;int k;
};
bool cmp(nod i,nod j){return i.p==j.p?i.k<j.k:i.p<j.p;}
vector<nod> q;
int main()
{
	long long l,r;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l>>r,q.push_back((nod){l,1}),q.push_back((nod){r+1,-1});
	sort(q.begin(),q.end(),cmp);
	long long last=0,now=0;
	for(int i=0;i<q.size();i++)
	{
		long long nex=q[i].p;
		ans[now]+=q[i].p-last,now+=q[i].k,last=nex;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
    return 0;
}
