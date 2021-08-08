#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7;
int  deep[N], n, k, a[N];

vector<int> g[N];
int sz[N], son[N];
ll ans = 0;


int  rt[N];

struct segment {
	int l, r;
	ll sum;
}tree[20 * N];

#define m (l + r) / 2
int top = 1;

void update(int v, int pos, int l, int r, int &node) {
	if (!node) node = top++;
	tree[node].sum += v;
	if (l == r) return;
	if (pos <= m) update(v, pos, l, m, tree[node].l);
	else update(v, pos, m + 1, r, tree[node].r);
}



ll query(int ql, int qr, int l, int r, int node) {
    if (qr < ql) return 0;
	if (ql <= l && qr >= r) {
		return tree[node].sum;
	}
	ll ans = 0;
	if (ql <= m) ans += query(ql, qr, l, m, tree[node].l);
	if (qr > m) ans += query(ql, qr, m + 1, r, tree[node].r);
	return ans;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	deep[u] = deep[fa] + 1;
	for (int to: g[u]) {
		dfs(to, u);
		sz[u] += sz[to];
		if (sz[son[u]] < sz[to]) {
			son[u] = to;
		}

	}
}

vector<pair<int, int> > cat;
vector<pair<int, int> >all;

void gao(int u, int fa) {
	cat.push_back({deep[u], a[u]});
	for (int to: g[u]) {
		gao(to, u);
	}
}

void cal(int u) {
	//cout << "U =  " << u << " " << a[u]<<endl;
	for (auto it: cat) {
		int va = it.first;
		int id = it.second;
	//	cout << "VA = " << va << " id " << id << endl;
		int dep = k - va + 2 * deep[u];
		id = 2 * a[u] - id;
	//	cout << "dep " << dep << " id " << id << endl;
        if (id >= 0)
		    ans += 1ll* query(1, dep , 1, N, rt[id]);
	//	cout << "idd = " << id << " a " << query(dep, 3 * n, 1, 3 * n, rt[id]) << endl;
	}

	for (auto it: cat) {
		int va = it.first;
		int id = it.second;
		//cout << "id " << id << "va " << va << endl;
		update(1, va, 1, N, rt[id]);
		all.push_back({va, id});
	}
}

void work(int u, int fa, int zson) {

	for (int to: g[u]) {
		if (to == zson) continue;
		cat.clear();
		gao(to, u);
		cal(u);	
	}
	//cout << "U = " << deep[u] << " id = " << a[u] << endl;
	update(1, deep[u], 1, N, rt[a[u]]);
	all.push_back({deep[u], a[u]});
}

void dfs1(int u, int fa, int ok) {
	for (int to: g[u]) {
		if (to == son[u]) continue;
		dfs1(to, u, 1);
	}
	if (son[u]) {
		dfs1(son[u], u, 0);
	}
	work(u, fa, son[u]);
	if (ok) {
		for (auto it: all) {
			int va = it.first;
			int id = it.second;
			update(-1, va, 1, N, rt[id]);
		}
		all.clear();
	}

}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++) {
		int x; scanf("%d", &x);
		g[x].push_back(i);
	}
	//deep[0] = -1;
	dfs(1, 0);
	dfs1(1, 0, 1);
	printf("%lld\n", ans + ans);

}