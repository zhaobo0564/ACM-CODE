#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef unsigned long long ull;
int n, q, a[N], b[N];
ull p[N], ha[N], base = 47, sum[N];

void init() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * base;
    }
    for (int i = 1; i <= n; i++) {
        ha[i] = ha[i - 1] + (ull)b[i] * p[n - i]; 
    }
}

ull get_hash(int l, int r) {
    return ha[r] - ha[l - 1];
}

#define m  (l + r) / 2
#define ls 2 * node
#define rs 2 * node + 1

struct {
    ull value, fn;
    int maxn;
} tree[4 * N];


void build(int l, int r, int node) {
    if (l == r) {
        tree[node].fn = p[n - l];
        tree[node].maxn = a[l];
        tree[node].value = tree[node].fn * (ull)a[l];
        return;
    }
    build(l, m, ls);
    build(m + 1, r, rs);
    tree[node].maxn = max(tree[ls].maxn, tree[rs].maxn);
    tree[node].value = tree[ls].value + tree[rs].value;
    tree[node].fn = tree[ls].fn + tree[rs].fn;
}

int flag[4 * N];

void push_up(int l, int r, int node) {
    if (flag[node]) {
        tree[ls].maxn += flag[node];
        tree[rs].maxn += flag[node];
        flag[ls] += flag[node];
        flag[rs] += flag[node];
        tree[ls].value = tree[ls].value + (tree[ls].fn) * (ull)flag[node];
        tree[rs].value = tree[rs].value + (tree[rs].fn) * (ull)flag[node];
        flag[node] = 0;
    }
}

void gao(int l, int r, int node) {
    if (tree[node].maxn < 99996) {
        return;
    }
    if (l == r) {
        tree[node].maxn = tree[node].maxn % 99996;
        tree[node].value = (ull)tree[node].maxn * tree[node].fn;
        return;
    }
    push_up(l, r, node);
    gao(l, m, ls);
    gao(m + 1, r, rs);
    tree[node].maxn = max(tree[ls].maxn, tree[rs].maxn);
    tree[node].value = tree[ls].value + tree[rs].value;

}

void update(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return;
    if (ql <= l && qr >= r) {
        tree[node].maxn += 1;
        tree[node].value = tree[node].value + tree[node].fn;
        flag[node] += 1; 
        if (tree[node].maxn >= 99996) {
            push_up(l, r, node);
            gao(l, r, node);
        }
        return;
    }
    push_up(l, r, node);
    if (ql <= m) update(ql, qr, l, m, ls);
    if (qr > m) update(ql, qr, m + 1, r, rs);
    tree[node].maxn = max(tree[ls].maxn, tree[rs].maxn);
    tree[node].value = tree[ls].value + tree[rs].value;
}

ull query(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        return tree[node].value;
    }
    ull ans = 0;
   	push_up(l, r, node);
    if (ql <= m) {
        ans += query(ql, qr, l, m, ls);
    } 
    if (qr > m) {
        ans += query(ql, qr, m + 1, r, rs);
    }
    return ans;
}

int solve(int pos) {
    int l = 1, r = n - pos + 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ull sum = query(pos, pos + mid - 1, 1, n, 1);
        
        ull sum1 = get_hash(pos, pos + mid - 1);
        if (sum == sum1) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    init();
    build(1, n, 1);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int l, r; scanf("%d %d", &l, &r);
            if (l > r) swap(l, r);
            update(l, r, 1, n, 1);
        } else {
            int pos; scanf("%d", &pos);
            printf("%d\n", solve(pos));
        }
    }
    return 0;

}