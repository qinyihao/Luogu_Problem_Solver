#include <bits/stdc++.h>
#define ll long long
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int dfsn[200005];
const int N = 2e5 + 6;
int head[N], Next[N], ver[N],vis[N],ok[N];
vector<int>g[N];
long long ans = 0;
int dfs(int u,int f = -1){
	vis[u]  = 1;
	for(int i = 0;i<g[u].size();i++){
		if(g[u][i] == f)  continue;;
		if(vis[g[u][i]]){
			ok[g[u][i]] = ok[u] = 1;
			return true;
		}
		if(dfs(g[u][i],u)){
			if(ok[u]) return false;
			ok[u] = 1;
			return true;
		}
	}
	return false;
}

long long dfs2(int u,int f = -1){
	long long ans =1;
	for(int i = 0;i<g[u].size();i++){
		if(g[u][i] == f)  continue;
		if(ok[g[u][i]]) continue;
		ans += dfs2(g[u][i],u);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		for(int i = 1;i<=n;i++){
			ok[i] = 0;
			vis[i] = 0;
			g[i].clear();
		}
		for(int i = 0;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		int cnt = 0;
		ans =(long long)n*(n-1);
		for(int i = 1;i<=n;i++){
			if(ok[i]){
				long long cnt = dfs2(i);
				ans -= cnt*(cnt-1)/2;
			}
		}
		cout<<ans<<endl;
	} 
    return 0;
}

  		 	 		 			 		 		 		 			   	
