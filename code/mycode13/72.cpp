 #include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
typedef long long ll;

ll tree[40 * N];
int n, a[N], ls[40 * N], rs[40 * N];
vector<int> g;
int top = 1, rt[N];

#define m ((l + r) / 2)

void update(int v, int pos, int l, int r, int last, int &now) {
	now = top++;
	tree[now] = tree[last];
	ls[now] = ls[last];
	rs[now] = rs[last];
	if (l == r) {
		tree[now] += 1ll * v;
		return;
	}
	if (pos <= m) update(v, pos, l, m, ls[last], ls[now]);
	else update(v, pos, m + 1, r, rs[last], rs[now]);
	tree[now] = tree[ls[now]] + tree[rs[now]];
}

ll query(ll ql, ll qr, int l, int r, int last, int now) {
	if (ql > qr) return 0;
	if (ql <= l && qr >= r) {
		return tree[now] - tree[last];
	}
	ll ans = 0;
	if (ql <= m) ans += query(ql, qr, l, m, ls[last], ls[now]);
	if (qr > m) ans += query(ql, qr, m + 1, r, rs[last], rs[now]);
	return ans;
}

ll work(int l, int r) {
	int maxn = 1000000000;
	ll ans = query(1, 1, 1, maxn,rt[l - 1], rt[r]);
	//cout << "ANS = " << ans << endl;
	if (ans == 0) return 1;
	ll L = 1, R = 2;
	ans = query(L, R, 1, maxn, rt[l - 1], rt[r]) - 1;
	//cout << "ans = " << ans << endl;
	if (ans == 0) return R;
	L = R + 1;
	R = R + ans;
	while (1) {
		ans = query(L, R, 1, maxn, rt[l - 1], rt[r]);
	//	cout << "L = " << L << " " << R << endl;
		if (ans == 0) return R; 
		L = R + 1;
		R = R + ans;
		
	}
	return R;
	
}

int main() {
	
	int maxn = 1000000000, q;
	scanf("%d", &n);
    scanf("%d", &q);
	//cout << (1ll*n + 1) * n / 2 << endl;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	
		update(a[i], a[i], 1, maxn, rt[i - 1], rt[i]);
	}
   
	ll ans = 0;
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		l = (l + ans);
		r = (r + ans);
        if (l >= n) {
            l -= n;
        } 
        if (r >= n) {
            r -= n;
        }
        l++, r++;
		if (l > r) swap(l, r);
		//cout << "l = " << l << " r = " << r << endl;
		ans = work(l, r);
		printf("%lld\n", ans);
        if (ans > n) ans %= n;
		
	}
	

}