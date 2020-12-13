#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define N 100010
#define M 1010

using namespace std;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int n, m, c, k, p, q;
unsigned long long a, x;
int wei[N];

int read() {
  int s = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}

int main() {
  n = read(), m = read(), c = read(), k = read();
  for (int i = 1; i <= n; i++) {
    cin >> a;
    x |= a;
  }
  for (int i = 0; i < k; i++) wei[i] = 1;
  for (int i = 1; i <= m; i++) {
    p = read(), q = read();
    if ((1ull << p) & x) wei[p] = 1;
    else wei[p] = 0; 
  }
  if (!n) {
    if (!m) {
      puts("18446744073709551616");
    } else {
      unsigned long long ans = 1;
      for (int i = 0; i < k; i++)
        if (wei[i] == 1) ans *= 2;
      cout << ans - n;
    }
    return 0;
  }
  unsigned long long ans = 1;
  for (int i = 0; i < k; i++)
    if (wei[i] == 1) ans *= 2;
  cout << ans - n;
}
