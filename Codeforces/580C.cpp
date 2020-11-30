#define watch(x) cout << (#x) << " is " << (x) << endl
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> adj_list;
vector<bool> check;
vector<bool> has_cat;
int original;
void dfs(int x, int cur_limit, int parent) {
    int my_limit;
    if (!has_cat[x]) {
        my_limit = original;
    }
    else {
        my_limit = cur_limit - 1;
    }
    if (my_limit < 0) return;
    bool is_leaf = true;
    for (int nei : adj_list[x]) {
        if (nei == parent) continue;
        dfs(nei, my_limit, x);
        is_leaf = false;
    }
    if (is_leaf) check[x] = true;
}

int solve(int n, int limit) {
    int ans = 0;
    check.resize(n, false);
    original = limit;
    dfs(0, limit, -1);

    for (bool b : check) {
        if (b) ++ans;
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, limit;
    cin >> n >> limit;
    has_cat.resize(n);
    adj_list.resize(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        has_cat[i] = x == 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    cout << solve(n, limit) << "\n";
    return 0;
}
