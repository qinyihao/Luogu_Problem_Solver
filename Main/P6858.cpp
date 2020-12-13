#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void read(T &x)
{
    x = 0;
    T f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}
const ll mod = 998244353;
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
ll qpow(ll a, ll b)
{
    ll p = mod - 2;
    ll ans = 1;
    while (p)
    {
        if (p & 1) ans = mul(ans, b);
        b = mul(b, b);
        p >>= 1;
    }
    return mul(ans, a);
}
ll g(ll n)
{
    if (n % 2 == 0)
    {
        return mul(n / 2, n + 3);
    } else {
        return mul(n, (n + 3) / 2);
    }
}
ll f[1000001];
int main()
{
    ll n, m;
    read(n);
    read(m);
    f[0] = g(n);
    for (int i = 1; i <= m; i++)
    {
        f[i] = (1 + mul(f[i - 1], qpow(i, i + n)) + mul(g(i + n) - 1, qpow(n, i + n))) % mod;
    }
    cout << f[m] << '\n';
    return 0;
}
