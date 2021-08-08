#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, q, a[N], pre[N], vis[N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

int tree[4 * N];

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        tree[node] = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}
set<int> g[N];

int nxt[N];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) { 
        scanf("%d", &a[i]);
        pre[i] = vis[a[i]];
        g[a[i]].insert(i);
       
        vis[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        update(i, pre[i], 1, n, 1);
    }
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x; scanf("%d", &x);
            auto it = g[a[x]].lower_bound(x);
            g[a[x]].erase(it);
            it = g[a[x]].upper_bound(x);
            if (it == g[a[x]].end()) {
                update(x, 0, 1, n, 1);
            } else {
                int y = *it;
                update(x, 0, 1, n, 1);
                if (it == g[a[x]].begin()) {
                    update(y, 0, 1, n, 1);
                } else {
                    it--;
                    update(y, *it, 1, n, 1);
                }
                
                
            }

            update(x, 0, 1, n, 1);
        } else {
            int l, r; scanf("%d %d", &l, &r);
            int ans = query(l, r, 1, n, 1);
            if (ans <= r && ans >= l) {
                puts("1");
            } else {
                puts("0");
            }
        }
    }
}