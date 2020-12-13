#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define N 100010
#define M 1010000

using namespace std;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int n, m, q; vector<int> ed[N];
ll mul[N], cnt[N], a[N], val[N];
int siz[N], qu[N], opt[N], pos[N], du[N];

ll read() {
  int s = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}

ll dfs(int x) {
  if (mul[x] != -1) return mul[x];
  if (opt[x] != 3) {
    mul[x] = (opt[x] == 1) ? 1 : val[x];
    return mul[x];
  }
  mul[x] = 1;
  for (int i = siz[x] - 1; i >= 0; i--) {
    int to = ed[x][i];
    mul[x] = (mul[x] * dfs(to)) % mod;
  }
  return mul[x];
}

void topsort() {
  queue<int> q;
  for (int i = 1; i <= m; i++)
    if (!du[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    ll prod = 1;
    for (int i = siz[x] - 1; i >= 0; i--) {
      int to = ed[x][i];
      cnt[to] = (cnt[to] + cnt[x] * prod % mod) % mod;
      du[to]--;
      if (!du[to]) q.push(to);
      prod = (prod * mul[to]) % mod;
    }
  }
  for (int i = 1; i <= m; ++ i) 
    if (opt[i] == 1)
      a[pos[i]] = (a[pos[i]] + val[i] * cnt[i] % mod) % mod;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    opt[i] = read();
    if (opt[i] == 1) pos[i] = read(), val[i] = read();
    if (opt[i] == 2) val[i] = read();
    if (opt[i] == 3) {
      siz[i] = read();
      for (int j = 1, x; j <= siz[i]; j++) {
        x = read(), ed[i].push_back(x);
        du[x]++;
      }
    }
  }
  memset(mul, -1, sizeof mul);
  for (int i = 1; i <= m; i++) 
    if (!du[i]) mul[i] = dfs(i);
  
  q = read();
  for (int i = 1; i <= q; i++) qu[i] = read();
  ll prod = 1;
  for (int i = q; i; i--) {
    cnt[qu[i]] = (cnt[qu[i]] + prod) % mod;
    prod = (prod * mul[qu[i]]) % mod;
  }
  for (int i = 1; i <= n; ++ i) a[i] = a[i] * prod % mod;
  topsort();
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
