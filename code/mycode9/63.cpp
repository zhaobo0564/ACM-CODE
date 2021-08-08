#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], block[N], n, m, vis[N], fn[300][N], cat[N], sum[N], L[N], R[N], ans[N];

struct node {
	int l, r, id, k1, k2;
};

vector<node>g[N];
vector<int> v;

bool cmp(node x, node y) {
	return x.r < y.r;
}

int get_id(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void add(int pos) {
	if (cat[vis[a[pos]]]) {
		if (cat[vis[a[pos]]] == 1) {
			sum[block[vis[a[pos]]]] -= 1;
		}
		cat[vis[a[pos]]]--;	
	}
	if (vis[a[pos]]) {
		fn[block[a[pos]]][vis[a[pos]]]--;
	}
	vis[a[pos]]++;
	fn[block[a[pos]]][vis[a[pos]]] += 1;
	cat[vis[a[pos]]]++;
	if (cat[vis[a[pos]]] == 1) {
		sum[block[vis[a[pos]]]] += 1; 
	}	
}

void del(int pos) {
	if (cat[vis[a[pos]]]) {
		if (cat[vis[a[pos]]] == 1) {
			sum[block[vis[a[pos]]]] -= 1;
		}
		cat[vis[a[pos]]]--;	
	}
	if (vis[a[pos]]) {
		fn[block[a[pos]]][vis[a[pos]]]--;
	}
	vis[a[pos]]--;
	if (vis[a[pos]]) {
		fn[block[a[pos]]][vis[a[pos]]] += 1;
		cat[vis[a[pos]]]++;
		if (cat[vis[a[pos]]] == 1) {
			sum[block[vis[a[pos]]]] += 1; 
		}	
	}
	
}

int work(int k) {
	int num = 0;
	for (int i = 1; i <= n; i = R[block[i]] + 1) {
		num += sum[block[i]];
		if (num >= k) {
			num -= sum[block[i]];
			for (int j = L[block[i]]; j <= R[block[i]]; j++) {
				if (cat[j]) {
					num++;
					if (num == k) {
						return j;
					}
				}
			}
		}
	}
	return 0;
}

int gao(int k, int x) {
	int num = 0;
	for (int i = 1; i <= n; i = R[block[i]] + 1) {
		num += fn[block[i]][x];
		if (num >= k) {
			num -= fn[block[i]][x];
			for (int j = L[block[i]]; j <= R[block[i]]; j++) {
				if (vis[j] == x) {
					num++;
					if (num == k) {
						return j;
					}
				}
			}
		}
	}
	return 0;
}

void solve() {
	for (int i = 1; i <= n; i = R[block[i]] + 1) {
		int pos = R[block[i]] + 1;
		for (int j  = 0; j < g[block[i]].size(); j++) {
			int l = g[block[i]][j].l;
			int r = g[block[i]][j].r;
			int id = g[block[i]][j].id;
			int k1 = g[block[i]][j].k1;
			int k2 = g[block[i]][j].k2;
			if (r <= R[block[i]]) {
				for (int k = l; k <= r; k++) {
					add(k);
				}
				int k = work(k1);
				ans[id] = gao(k2, k);
				for (int k = l; k <= r; k++) {
					del(k);
				}
			} else {
				while (pos <= r) {
					add(pos);
					pos++;
				}
				for (int k = l; k <= R[block[i]]; k++) {
					add(k);
				}
				int k = work(k1);
				ans[id] = gao(k2, k);
				for (int k = l; k <= R[block[i]]; k++) {
					del(k);
				}
			} 
		}
		if (g[block[i]].size() == 0) continue;
		for (int j = R[block[i]] + 1; j <= g[block[i]][g[block[i]].size() - 1].r; j++) {
			del(j);
		}
	}
}


int main() {
	scanf("%d", &n);
	int b = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		v.push_back(a[i]);
		block[i] = i / b;
		L[block[i]] = n + 1;
		R[block[i]] = 0;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) {
		a[i] = get_id(a[i]);
		L[block[i]] = min(L[block[i]], i);
		R[block[i]] = max(R[block[i]], i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r, k1, k2; scanf("%d %d %d %d", &l, &r, &k1, &k2);
		g[block[l]].push_back({l, r, i, k1, k2});
	}
	for (int i = 1; i <= n; i = R[block[i]] + 1) {
		sort(g[block[i]].begin(), g[block[i]].end(), cmp);
	}
	solve();
	for (int i = 1; i <= m; i++) {
		printf("%d\n", v[ans[i]- 1]);
	}

}