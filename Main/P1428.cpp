#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
int n;
vector<int> f, g;

struct Fenwick_tree
{
    int c[1001];
    int lowbit(int x) { return x & (-x); }
    void add(int x)
    {
        while (x <= n)
        {
            c[x]++;
            x += lowbit(x);
        }
    }
    int sum(int x)
    {
        if (x <= 0)
            return 0;
        int ret = 0;
        while (x)
        {
            ret += c[x];
            x -= lowbit(x);
        }
        return ret;
    }
} t;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        g.push_back(x);
        f.push_back(x);
    }
    sort(g.begin(), g.end());
    unique(g.begin(), g.end());
    for (int i = 0; i < n; i++)
    {
        f[i] = lower_bound(g.begin(), g.end(), f[i]) - g.begin() + 1;
        printf("%d ", t.sum(f[i] - 1));
        t.add(f[i]);
    }
    cout << endl;
    return 0;
}
