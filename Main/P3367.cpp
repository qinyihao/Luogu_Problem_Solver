#include <cstdio>
int father[10001];
int findFather(int x) {
	if (father[x] != x) {
		father[x] = findFather(father[x]);
	}
	return father[x];
}
void merge(int x, int y) {
	x = findFather(x);
	y = findFather(y);
	if (x != y) father[x] = y;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i += 1) {
		father[i] = i;
	}
	for (int i = 1; i <= m; i += 1) {
		int oper, a, b;
		scanf("%d%d%d", &oper, &a, &b);
		if (oper - 1) {
			printf( findFather(a) == findFather(b) ? "Y\n" : "N\n" );
		} else {
			merge(a, b);
		}
	}
	return 0;
} 
