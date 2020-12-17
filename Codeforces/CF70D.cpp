#include <bits/stdc++.h>
using namespace std;
 
int n;
map<int, int> up, down;
 
int orientation(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
	pair<int,int> ab = {b.first - a.first, b.second - a.second};
	pair<int,int> bc = {c.first - b.first, c.second - b.second};
	int64_t cross = 1ll * ab.first * bc.second - 1ll * ab.second * bc.first;
	if(cross < 0) return -1;
	if(cross > 0) return 1;
	return 0;
}
 
bool inside(map<int, int>& mp, int x, int y) {
	if(mp.count(x)) return y <= mp[x];
	auto itr = mp.upper_bound(x);
	auto itl = itr;
	if(itr == mp.end() || itl == mp.begin()) return false;
	--itl;
	return orientation(*itl, make_pair(x, y), *itr) >= 0;
}
 
void add(map<int, int>& mp, int x, int y) {
	if(inside(mp, x, y)) return; // assumes no three at same x
	mp[x] = y;
	auto it = mp.upper_bound(x);
	if(it != mp.end()) while(next(it) != mp.end() && orientation(make_pair(x, y), *it, *next(it)) >= 0) {
		it = mp.erase(it);
	}
	it = mp.find(x);
	if(it == mp.begin()) return;
	it = prev(it);
	while(it != mp.begin() && orientation(*prev(it), *it, make_pair(x, y)) >= 0) {
		it = prev(mp.erase(it));
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, inst, x, y; i < n; i++) {
		cin >> inst >> x >> y;
		if(inst == 1) {
			add(up, x, y);
			add(down, x, -y);
		} else cout << (inside(up, x, y) && inside(down, x, -y) ? "YES\n" : "NO\n");
	}
}
