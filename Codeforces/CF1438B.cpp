#include <bits/stdc++.h>
#define M 1001
int t, n, b[M];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                if (b[i] == b[j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
