#include <bits/stdc++.h>
using namespace std;
int ans = 0;
char string1[1000], string2[1000];
int main()
{
    scanf("%s", string1 + 1);
    scanf("%s", string2 + 1);
    for(int i = 1; i <= strlen(string1 + 1); ++i)
    {
        for(int j = 2; j <= strlen(string2 + 1); ++j)
        {
            if(string1[i] == string2[j] && string1[i + 1] == string2[j - 1])
            {
                ++ans;
            }
        }
    }
    printf("%d", 1<<ans);
    return 0;
}
