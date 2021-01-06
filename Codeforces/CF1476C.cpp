#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int n;
    cin >> n;
    map<int,int> cnts;
    forn(i, n) {
        int val;
        cin >> val;
        cnts[val]++;
    }
    vector<int> c(n + 1);
    for (auto e: cnts)
        c[e.second]++;
    for (int i = n - 1; i >= 0; i--)
        c[i] += c[i + 1];
    int sum = 0;    
    int best = 0, best_x = 0, best_y = 0;
    for (int x = 1; x <= n; x++) {
        sum += c[x];
        int y = sum / x;
        if (y >= x && best < x * y) {
            best = x * y;
            best_x = x;
            best_y = y;
        }
    }
    cout << best << endl;
    cout << best_x << " " << best_y << endl;
    vector<vector<int>> r(best_x, vector<int>(best_y));
    int pos = 0;
    sum = 0;
    for (auto e: cnts)
        if (e.second >= best_x) {
            forn(i, best_x)
                r[i % best_x][(pos + i) % best_y] = e.first;
            pos++;
            sum += best_x;
        }
    int xx = 0;
    int yy = pos;
    for (auto e: cnts)
        if (e.second < best_x) {
            int lim = min(e.second, best - sum);
            forn(i, lim) {
                while (r[xx][yy] != 0) {
                    xx = 0;
                    yy = (yy + 1) % best_y;
                }
                r[xx][yy] = e.first;
                xx = (xx + 1) % best_x;
                yy = (yy + 1) % best_y;
            }
            sum += lim;
        }
 
    forn(i, r.size()) {
        forn(j, r[i].size()) {
            if (j > 0)
                cout << " ";
            cout << r[i][j];
        }
        cout << endl;
    }
    return 0;
}
