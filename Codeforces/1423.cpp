#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <time.h>
#include <complex>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
#include <bitset>

#pragma warning(disable:4996)
#define PII std::pair<long long, long long>
#define PTT std::pair<tree *, tree *>

template<typename T> T min(T x, T y)
{
	return x < y ? x : y;
}
template<typename T> T max(T x, T y)
{
	return x > y ? x : y;
};

const int INF = 2000000005;// 0000;//autojs.org
const long long mod = 1000000007;// 998244353;//
const long long MAXN = 100005;

struct node {
	node *fa;
	int x;
	node *mn;
	bool rev;
	int w;
	int size;
	node *son[2];
	node(int MN = INF)
	{
		fa = son[0] = son[1] = NULL;
		x = MN; mn = this;
		rev = false;
		w = size = 1;
	}
};

int from(node *son, node *fa)
{
	if (!fa)
		return -1;
	if (son == fa->son[0])
		return 0;
	if (son == fa->son[1])
		return 1;
	return -1;
}
void pushdown(node *T)
{
	if (!T->rev)
		return;
	std::swap(T->son[0], T->son[1]);
	if (T->son[0])
		T->son[0]->rev ^= 1;
	if (T->son[1])
		T->son[1]->rev ^= 1;
	T->rev = false;
}
void path_pushdown(node *T)
{
	static node *S[MAXN];
	int top = 0;
	while (T)
		S[++top] = T,
		T = T->fa && from(T, T->fa) != -1 ? T->fa : NULL;
	while (top)
		pushdown(S[top--]);
}
void fix(node *T)
{
	if (!T)
		return;
	T->size = T->w + (T->son[0] ? T->son[0]->size : 0) + (T->son[1] ? T->son[1]->size : 0);
	T->mn = T;
	if (T->son[0] && T->son[0]->mn->x < T->mn->x)
		T->mn = T->son[0]->mn;
	if (T->son[1] && T->son[1]->mn->x < T->mn->x)
		T->mn = T->son[1]->mn;
}
void rotate(node *T, int ty)//0左旋
{
	node *f = T->fa, *ch = T->son[1 ^ ty], *chch = ch->son[0 ^ ty];
	if (f)
		f->son[from(T, f)] = ch;
	ch->fa = f;
	ch->son[0 ^ ty] = T;
	T->fa = ch;
	T->son[1 ^ ty] = chch;
	if (chch)
		chch->fa = T;
	fix(T);
	fix(ch);
}
void raise(node *T)
{
	node *f = T->fa;
	rotate(f, from(T, f) ^ 1);
}
void _splay(node *T)
{
	if (from(T, T->fa) == -1)
		return;
	if (from(T->fa, T->fa->fa) == -1)
		return raise(T);
	node *f = T->fa, *ff = f->fa;
	if (from(T, f) == from(f, ff))
		raise(f), raise(T);
	else
		raise(T), raise(T);
	_splay(T);
}
void splay(node *T)
{
	path_pushdown(T);
	_splay(T);
}
node *leftmost(node *T)
{
	splay(T);
	while (T->son[0])
		T = T->son[0], pushdown(T);
	return T;
}

namespace LCT {
	node v[MAXN * 2];

	void access(node *T)
	{
		splay(T);
		if (T->son[1]) 
			T->w += T->son[1]->size;
		T->son[1] = NULL; fix(T);
		while (T->fa)
		{
			node *p = T->fa;
			splay(p);
			p->w += (p->son[1] ? p->son[1]->size : 0) - T->size;
			p->son[1] = T; fix(p);
			T = p;
		}
		splay(T);
	}
	void makeroot(node *T)
	{
		access(T);
		splay(T);
		T->rev ^= 1;
	}
	node *getroot(node *T)
	{
		access(T);
		return leftmost(T);
	}
	void makeroot(int id)
	{
		makeroot(v + id);
	}
	void link(int x, int y)
	{
		makeroot(v + x);
		makeroot(v + y);
		v[x].fa = v + y;
		v[y].w += v[x].size;
		fix(v + y);
	}
	void cut(int x, int y)
	{
		makeroot(v + x);
		access(v + y);
		splay(v + x);
		v[x].son[from(v + y, v + x)] = NULL; fix(v + x);
		v[y].fa = NULL;
	}
	void modify(int id, int x)
	{
		makeroot(v + id);
		access(v + id);
		v[id].x = x;
	}
	int query(int x, int y)
	{
		makeroot(v + x);
		access(v + y);
		splay(v + y);
		return (int)(v[y].mn - v);
	}
	int size(int id)
	{
		makeroot(id);
		splay(v + id);
		return v[id].size;
	}
	bool linked(int x, int y)
	{
		return getroot(v + x) == getroot(v + y);
	}
}

int N, Q, K, date = 1;
int uu[MAXN * 5], vv[MAXN * 5], cnt;
std::queue<int> q, e;//空余结点编号，保留的边
int E[MAXN*5], V[MAXN*5], D[MAXN*5];//结点编号->边的编号,边->结点，边->日期
bool del[MAXN * 5];//删除标记

void opt1(int x, int y)
{
	e.push(++cnt);
	uu[cnt] = x; vv[cnt] = y;

	if (LCT::linked(x, y))
	{
		int v = LCT::query(x, y);
		LCT::cut(v, uu[E[v]]);
		LCT::cut(v, vv[E[v]]);
		del[E[v]] = true;
		q.push(v);
	}
	int v = q.front(); q.pop();
	V[cnt] = v;
	E[v] = cnt;
	D[cnt] = date;
	LCT::modify(v, date);
	LCT::link(v, x);
	LCT::link(v, y);
}
void opt2(int x)
{
	int ans = LCT::size(x);
	printf(" %d\n", (ans + 1) / 2);
}
void opt3()
{
	date++;
	while (e.size() && D[e.front()] == date - K)
	{
		int id = e.front(); e.pop();
		if (del[id])
			continue;
		int v = V[id];
		LCT::cut(v, uu[id]);
		LCT::cut(v, vv[id]);
		del[id] = true;
		q.push(v);
	}
}

int main()
{
	long long ST = clock();

	int ty, x, y;

	scanf("%d %d %d", &N, &Q, &K);
	for (int i = N + 1; i <= 2 * N; i++)
		q.push(i);

	while (Q--)
	{
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d %d", &x, &y);
			opt1(x, y);
		}
		else if (ty == 2)
		{
			scanf("%d", &x);
			opt2(x);
		}
		else
			opt3();
	}
	return 0;
}
