#include <bits/stdc++.h>
using namespace std;

int n, m;
double maxans = -1.0;

double perpeople()
{
    double total = 0;
    double maxn = -1, minn = 99999;
    for (int i = 1; i <= m; ++i)
    {
        double score;
        cin >> score;
        total += score;
        maxn = max(score, maxn);
        minn = min(score, minn);
    }
    total -= maxn;
    total -= minn;
    double avg = total / (m - 2) * 1.0;
    return avg;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        maxans = max(maxans, perpeople());
    }
    cout << setprecision(2) << fixed << maxans;
    return 0;
}
