#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int i, r;
    cin >> n;
    for (i = n; i >= 0; --i)
    {
        cin >> r;
        if (r == 0) continue;
        if (r > 0 && i != n) cout<<"+";
        if (i == 0)
        {        
          cout << r;
          continue;
        }
        if (i != 0)
        {            
            if (r != 1 && r != -1) cout << r;
            else
            {
                if (r == -1) cout << "-";
             } 
        }
        if (i == 1) cout << "x";
          else cout << "x^" << i;
    return 0;
    }
}
