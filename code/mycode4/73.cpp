#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], q, top = 1, rt, maxn;

struct segement {
	int l, r, sum;
}tree[30 * N];

#define m (l + r) / 2

map<int, int> g;


void update(int val, int &now, int pos, int l, int r) {
	if (!now) now = top++;
	if (l == r) {
	//	cout <<"val "<< val << "pos" << pos << endl;
		tree[now].sum = val;
		return;
	}
	if (pos <= m) update(val, tree[now].l, pos, l, m);
	else update(val, tree[now].r, pos, m + 1, r);

	tree[now].sum = min(tree[tree[now].l].sum, tree[tree[now].r].sum);

}

int query(int now, int ql, int qr, int l, int r) {
	if (l > r) return 2e9;
	if (ql <= l && qr >= r) {
		return tree[now].sum;
	}
	int ans = INT_MAX;
	if (ql <= m) ans = min(ans, query(tree[now].l, ql, qr, l, m));
	if (qr > m) ans = min(ans, query(tree[now].r, ql, qr, m + 1, r));
	return ans;
}


void add(int x) {
	g[x]++;
	auto it = g.lower_bound(x);
	if (it -> second > 1) {
		update(0, rt, x, 1, maxn);
	} else {
		if (it != g.begin()) {
			it--;
			update(x - (it -> first), rt, x, 1, maxn);
			it++;
		}
		if (it != g.end()) {
			it++;
			if (it != g.end()) {
				update((it -> first) - x, rt, (it -> first), 1, maxn);
			}
		}
	}

}

void deleate(int x) {
	g[x]--;
	//cout << g[x] << endl;
	if (g[x] == 0) {
		auto it = g.lower_bound(x);
		update(2e9, rt, x, 1, maxn);
		if (it != g.begin() && it != g.end()) {
			int cat = it -> first;
			it--;
			update(cat - (it -> first), rt, cat, 1, maxn);
		}
	} else if(g[x] == 1) {
		auto it = g.lower_bound(x);
		if (it != g.begin()) {
			it--;
			update(x - (it -> first), rt, x, 1, maxn);
			//cout <<"***" << endl;
		} else {
			update(2e9, rt, x, 1, maxn);
		}
	} 

}

int ask(int x) {
	auto it = g.upper_bound(x / 2);
	if (it == g.end()) return 2e9;
	if (it -> second > 1) return it -> first;
	if (it != g.begin()) {
		int cat = it -> first;
		it--;
		cat += it -> first;
		if(cat > x) return it -> first;
		it++;
	}
	it++;
	if (it != g.end()) {
		it--;
		return it -> first;
	}
	return 2e9;
}




int main () {
	scanf("%d", &q);
	for (int i = 0; i <= 2000000; i++) {
		tree[i].sum = INT_MAX;
		tree[i].l = tree[i].r = 0;
	}
	maxn = 1e9 + 7;
	while (q--) {
		int op, x;
		scanf("%d %d", &op, &x);
		if (op == 1) {
			add(x);
		} else if (op == 2) {
			deleate(x);
		} else if (op == 3) {
		//	cout << ask(x) << endl;
			int ans = query(rt, ask(x), maxn, 1, maxn);
			//cout << ans << endl;
			if (ans < x) puts("Yes");
			else puts("No");
		}
	}
}

