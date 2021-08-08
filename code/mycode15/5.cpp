#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int> g[N];

int n, q, fa[N][20], deep[N], id[N], cat[N], o = 1;

void dfs(int u, int f) {
    id[u] = o++;
    cat[id[u]] = u;
    fa[u][0] = f;
    deep[u] = deep[f] + 1;
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[x] < deep[y]) {
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    for (int i = 0; i <= 19; i++) {
        if (d & 1) {
            x = fa[x][i];
        }
        d = d / 2;
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

struct {
    int maxn, minn, lca;
    int maxn_pos, minn_pos;
} tree[4 * N];

#define ls (node << 1)
#define rs (node << 1 | 1)
#define m (l + r >> 1)


void build(int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = tree[node].minn = id[l];
        tree[node].lca = tree[node].maxn_pos = tree[node].minn_pos = l;
        return;
    }
    build(l, m, ls);
    build(m + 1, r, rs);
    tree[node].maxn = max(tree[ls].maxn, tree[rs].maxn);
    if (tree[node].maxn == tree[ls].maxn) {
        tree[node].maxn_pos = tree[ls].maxn_pos;
    } else {
        tree[node].maxn_pos = tree[rs].maxn_pos;
    }
    tree[node].minn = min(tree[ls].minn, tree[rs].minn);
    if (tree[node].minn == tree[ls].minn) {
        tree[node].minn_pos = tree[ls].minn_pos;
    } else {
        tree[node].minn_pos = tree[rs].minn_pos;
    }
 //   cout << "ls " << tree[ls].lca << " rs = " << tree[rs].lca << "lca " << get_lca(tree[ls].lca, tree[rs].lca) << endl;
    tree[node].lca = get_lca(tree[ls].lca, tree[rs].lca);
}

int maxn, minn, lca, maxn_pos, minn_pos;

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        if (lca == 0) lca = tree[node].lca;
        else lca = get_lca(tree[node].lca, lca);
        if (tree[node].maxn > maxn) {
            maxn = tree[node].maxn;
            maxn_pos = tree[node].maxn_pos;
        }
        if (tree[node].minn < minn) {
            minn = tree[node].minn;
            minn_pos = tree[node].minn_pos;
        }
        return;
    }
    if (ql <= m) query(ql, qr, l, m, ls);
    if (qr > m) query(ql, qr, m + 1, r, rs);
}



int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        g[x].push_back(i);
    }
    dfs(1, 0);
    build(1, n, 1);
   // cout << tree[1].lca << endl;
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        maxn = 0, minn = INT_MAX, lca = 0;
        query(l, r, 1, n, 1);
        //cout << "maxn_pos = " << maxn_pos << endl;
        //cout << "MINN_pos = " << minn_pos << endl;
     //   cout << "lca " << lca << endl;
        int posl = minn_pos, posr = maxn_pos;
        int ans = 0, lca1 = 0, ans2 = 0, lca2 = 0;
        if (posl - 1 >= l) {
            lca = 0;
            query(l, posl - 1, 1, n, 1);
            lca1 = lca;
        //    cout << "lca = " << lca << endl;
            ans = max(ans, deep[lca1]);
        }
        if (posl + 1 <= r) {
            lca = 0;
            query(posl + 1, r, 1, n, 1);
            if (lca1 == 0) lca1 = lca;
            else lca1 = get_lca(lca1, lca);
           /// cout << "LCA " << lca << endl;
        }
      //  cout << "lca1 " << lca1 << endl;
        ans = deep[lca1];
        if (posr - 1 >= l) {
            lca = 0;
            query(l, posr - 1, 1, n, 1);
            lca2 = lca;
        }
        if (posr + 1 <= r) {
            lca = 0;
            query(posr + 1, r, 1, n, 1);
            if (lca2 == 0) lca2 = lca;
            else lca2 = get_lca(lca2, lca);
        }
    //    cout << "lca2 = " << lca2 << endl;
        ans2 = deep[lca2];
        if (ans >= ans2) {
            printf("%d %d\n", posl, ans - 1);
        } else {
            printf("%d %d\n", posr, ans2 - 1);
        }
    }
}