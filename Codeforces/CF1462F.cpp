#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int x[maxn], y[maxn];
int main(){
	int t; scanf("%d",&t);
	while(t --){
		int n; scanf("%d",&n);
		for(int i = 1; i <= n; i ++){
			scanf("%d%d",&a[i], &b[i]);
			x[i] = a[i];
			y[i] = b[i];
		}
		sort(x + 1, x + n + 1);
		sort(y + 1, y + n + 1);
		int l, r, ans = n;
		for(int i = 1; i <= n; i ++){
			int l = lower_bound(y + 1, y + n + 1, a[i]) - y - 1;
			int r = n - (upper_bound(x + 1, x + n + 1, b[i]) - x) + 1;
			ans = min(ans, l + r); 
		}
		printf("%d\n", ans);
	}
	return 0;
}
