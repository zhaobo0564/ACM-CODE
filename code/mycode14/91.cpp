#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct segment {
    int sum[12];
    int maxn;
}tree[4 * N];

int n, flag[4 * N][12], q;

vector<int> g[20];

#define m (l + r >> 1)
#define ls (node << 1)
#define rs (node << 1 | 1) 

void push_up(int node) {
    for (int i = 2; i <= 10; i++) {
        if (flag[node][i]) {
            tree[ls].sum[i] += flag[node][i];
            tree[rs].sum[i] += flag[node][i];
            tree[ls].maxn = max(tree[ls].maxn, tree[ls].sum[i]);
            tree[rs].maxn = max(tree[rs].maxn, tree[rs].sum[i]);
            flag[ls][i] += flag[node][i];
            flag[rs][i] += flag[node][i];
            flag[node][i] = 0; 
        }
    }
}

void update(int id, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        for (int i: g[id]) {
            tree[node].sum[i]++;
            flag[node][i]++;
        }
        for (int i = 2; i <= 10; i++) {
            tree[node].maxn = max(tree[node].maxn, tree[node].sum[i]);
        }
        return;
    }
    push_up(node);
    if (ql <= m) update(id, ql, qr, l, m, ls);
    if (qr > m) update(id, ql, qr, m + 1, r, rs);
    tree[node].maxn = max(tree[ls].maxn, tree[rs].maxn);
    for (int i = 2; i <= 10; i++) {
        tree[node].sum[i] = max(tree[ls].sum[i], tree[rs].sum[i]);
    }
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].maxn;
    }
    int ans = 0;
    push_up(node);
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, ls));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rs));
    return ans;
}


int main() {
    scanf("%d %d", &n, &q);
    g[2].push_back(2);
    g[3].push_back(3);
    g[4].push_back(2), g[4].push_back(2);
    g[5].push_back(5);
    g[6].push_back(2), g[6].push_back(3);
    g[7].push_back(7);
    g[8].push_back(2), g[8].push_back(2), g[8].push_back(2);
    g[9].push_back(3), g[9].push_back(3);
    g[10].push_back(2), g[10].push_back(5);
    while (q--) {
        char op[10];
        scanf("%s", op);
        if (op[1] == 'U') {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            update(x, l, r, 1, n, 1);

        } else {
            int l, r; scanf("%d %d", &l, &r);
            printf("ANSWER %d\n", query(l, r, 1, n, 1));
        }
    }
    

}