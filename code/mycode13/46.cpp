#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int mp[5007][5007];

int n, q, fa[N], sz[N];

struct qu{
	int u, v, op;
}Q[N];

vector<int> tree[4 * N];

#define m (l + r >> 1)
#define lson (node << 1)
#define rson (node << 1 | 1)

void update(int v, int ql, int qr, int l, int r, int node) {
	if (ql <= l && qr >= r) {
		tree[node].push_back(v);
		return;
	}
	if (ql <= m) update(v, ql, qr, l, m, lson);
	if (qr > m) update(v, ql, qr, m + 1, r, rson);
}

int find(int x) {
	if (x != fa[x]) {
		return find(fa[x]);
	}
	return x;
}
int top = 1, Stack[N];


void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	if (sz[fx] > sz[fy]) {
		swap(fx, fy);
	}
	Stack[top++] = fx;
	fa[fx] = fy;
	sz[fy] += sz[fx];

}

void del(int x) {
	while (top > x) {
		int y = Stack[top - 1];
		sz[fa[y]] -= sz[y];
		fa[y] = y;
		top--;
	}
}

void dfs(int l, int r, int node) {
	int cur = top;
	for (int i = 0; i < tree[node].size(); i++) {
		merge(Q[tree[node][i]].u, Q[tree[node][i]].v);
	}
	if (l == r) {
		if (Q[l].op == 2) {
			
			int fx = find(Q[l].u);
			int fy = find(Q[l].v);
			if (fx == fy) {
				puts("Y");
			} else {
				puts("N");
			}
			
		}
		del(cur);
		return;
	}
	dfs(l, m, lson);
	dfs(m + 1, r, rson);
	del(cur);
}


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < N; i++) {
		fa[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= q; i++) {
		int op, u, v;
		scanf("%d %d %d", &op, &u, &v);
		if (u > v) swap(u, v);
		if (op == 0) {
			mp[u][v] = i;
		} else if (op == 1) {
			update(mp[u][v], mp[u][v], i, 1, q, 1);
			mp[u][v] = 0;
		}
		Q[i] = {u, v, op};
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mp[i][j]) {
				update(mp[i][j], mp[i][j], q, 1, q, 1);
			}
		}
	}
	dfs(1, q, 1);
}
