#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, s;
    cin >> a >> s;
    int a1, s1, a2 = 1, s2 = 1;
    a1 = a.size();
    s1 = s.size();
    for (int i = 0; i < a1; i++)
        a2 *= a[i] - 'A' + 1;
    for (int i = 0; i < s1; i++)
        s2 *= s[i] - 'A' + 1;
    if (a2 % 47 == s2 % 47)
        cout << "GO";
    else
        cout << "STAY";
    return 0;
}
