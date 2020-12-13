#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[10001] ={0};
    int b[10001] = {0};
    int c[10001] = {0};
    int d[10001] = {0}; 
    int x;
    int y;
    int k = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    cin >> x >> y;
    for (int i = 1 ;i <=n ;i++)
    {
        if (x-a[i] >= 0 && x-a[i] <= c[i] && y - b[i] >= 0 && y - b[i] <= d[i])
        {
            k = i;
        }  
    }   cout<< k <<endl;
    return 0;
}
