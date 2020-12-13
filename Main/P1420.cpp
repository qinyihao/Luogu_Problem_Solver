#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a = -2, b, cnt = 1, maxi = 1;
    for(cin >> n; n--; a=b)
        cin >> b, cnt = (b-a-1) ? 1 : (maxi=max(maxi,cnt+1),cnt+1);
    cout << maxi << endl;
    return 0;
}
