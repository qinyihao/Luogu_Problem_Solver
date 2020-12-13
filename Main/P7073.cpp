#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 8;
struct node {
	int l, r, op, v, id;  // op 0: !, 1: &, 2: |, digit: -1
} d[maxn];
int n, val[maxn], tot = 0;
string s;
int st[maxn], top, q, x;
bool vis[maxn];
inline int read() {
	register int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void dfs(int v) {
	if (d[v].op == -1) {
		vis[d[v].id] = true;
		return;
	}
	if (d[v].op == 0) {
		dfs(d[v].l);
	} else if (d[v].op == 1) {
		int l = d[v].l, r = d[v].r;
		if (d[l].v + d[r].v == 2) {
			dfs(l);
			dfs(r);
		} else if (d[l].v) {
			dfs(r);
		} else if (d[r].v) {
			dfs(l);
		}
	} else {
		int l = d[v].l, r = d[v].r;
		if (d[l].v + d[r].v == 0) {
			dfs(l);
			dfs(r);
		} else if (!d[l].v) {
			dfs(r);
		} else if (!d[r].v) {
			dfs(l);
		}
	}
}
int main() {
//	freopen("expr.in", "r", stdin);
//	freopen("expr.out", "w", stdout);
	getline(cin, s);
	n=read();
	for (int i = 1; i <= n; ++i) {
		val[i]=read();
	}
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'x') {
			int p = 0;
			while (isdigit(s[i + 1])) {
				p = p * 10 + s[i + 1] - '0';
				i++;
			}
			tot++;
			d[tot].v = val[p];
			d[tot].id = p;
			d[tot].op = -1;
			st[++top] = tot;
		} else if (s[i] == '!') {
			tot++;
			d[tot].v = !d[st[top]].v;
			d[tot].l = st[top--];
			d[tot].op = 0;
			st[++top] = tot;
		} else if (s[i] == '&') {
			tot++;
			d[tot].v = d[st[top]].v & d[st[top - 1]].v;
			d[tot].op = 1;
			d[tot].l = st[top--];
			d[tot].r = st[top--];
			st[++top] = tot;
		} else if (s[i] == '|') {
			tot++;
			d[tot].v = d[st[top]].v | d[st[top - 1]].v;
			d[tot].op = 2;
			d[tot].l = st[top--];
			d[tot].r = st[top--];
			st[++top] = tot;
		}
	}
	dfs(tot);
	bool res = d[tot].v;
	q=read();
	while (q--) {
		x=read();
		if (vis[x]) printf("%d\n",!res);
		else printf("%d\n",res);
	}
	return 0;
}
