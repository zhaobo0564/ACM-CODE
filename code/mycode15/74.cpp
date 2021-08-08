#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
#define int long long
ll n, u[N], v[N], c[N], sum[N];
ll flag[4 * N];

struct segment {
    ll maxn, minn;
    int ok;
    segment() {
        this->maxn = 0;
        this->minn = 0;
        this->ok = 0;
    }
} tree[4 * N];

#define m (l + r) / 2
#define ls node * 2
#define rs node * 2 + 1

segment merge(segment x, segment y) {
    if (x.ok == -1) return y;
    segment z;
    z.maxn = max(x.maxn, y.maxn);
    z.minn = min(x.minn, y.minn);
    if (x.ok && y.ok) {
        if (x.maxn <= y.minn) {
            z.ok = 1;
            return z;
        } else {
            z.ok = 0;
            return z;
        }
    } else {
        z.ok = 0;
        return z;
    }
}


// maxn -> u, minn -> v
void build(int l, int r, int node) {
    flag[node] = 0;
    tree[node].ok = 0;
    tree[node].maxn = tree[node].minn = 0;
    if (l == r) {
        tree[node].maxn = u[l] + sum[l];
        tree[node].minn = v[l] + sum[l];
        tree[node].ok = 1;
        return;
    }
    build(l, m, ls);
    build(m + 1, r, rs);
    tree[node] = merge(tree[ls], tree[rs]);
}

void push_down(int node) {
    if (flag[node]) {
        tree[ls].maxn += flag[node];
        tree[rs].maxn += flag[node];  
        tree[ls].minn += flag[node];
        tree[rs].minn += flag[node];
        flag[ls] += flag[node];
        flag[rs] += flag[node];
        flag[node] = 0;
    }
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node].maxn += v;
        tree[node].minn += v;
        flag[node] += v;
        return;
    } 
    push_down(node);
    if (ql <= m) update(v, ql, qr, l, m, ls);
    if (qr > m) update(v, ql, qr, m + 1, r, rs);
    tree[node] = merge(tree[ls], tree[rs]);
}

void up(ll U, ll V, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].maxn += U;
        tree[node].minn += V;
        tree[node].ok = 1;
        return;
    }
    push_down(node);
    if (pos <= m) up(U, V, pos, l, m, ls);
    else up(U, V, pos, m + 1, r, rs);
    tree[node] = merge(tree[ls], tree[rs]);
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment ans;
    ans.ok = -1;
    push_down(node);
    if (ql <= m) ans = merge(ans, query(ql, qr, l, m, ls));
    if (qr > m) ans = merge(ans, query(ql, qr, m + 1, r, rs));
    return ans;
}

void clear() {
    for (int i = 0; i <= n + 1; i++) {
        sum[i] = 0;
    }

}

void solve() {
    scanf("%lld", &n);
    clear();
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &u[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = n - 1; i; i--) {
        sum[i] = c[i] + sum[i + 1];
    }
    build(1, n, 1);
    int q; scanf("%lld", &q);
    while (q--) {
        int op; scanf("%lld", &op);
        if (op == 0) {
            int l, r; scanf("%lld %lld", &l, &r);
            segment ans = query(l, r, 1, n, 1);
            if (ans.ok) {
                puts("Yes");
            } else {
                puts("No");
            }

        } else if (op == 1) {
            int i, w; scanf("%lld %lld", &i, &w);
            update(w - c[i], 1, i, 1, n, 1);
            c[i] = w;

        } else if (op == 2) {
            int i, p, q; scanf("%lld %lld %lld", &i, &p, &q);
            up(p - u[i], q - v[i], i, 1, n, 1);
            u[i] = p, v[i] = q;
        }
    }
}

int32_t main() {
    int t; scanf("%lld", &t);
    while (t--) {
        solve();
    }
    return 0;
}