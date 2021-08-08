#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

struct hjt {
    int l, r, sum;
}tree[40 * N];

int top = 1, n, mm, q, rt[N], fa[N], vis[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

struct edge{
    int u, v;
}e[N];

#define m (l + r) / 2

void update(int v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum = v;
        return;
    }
    if (pos <= m) {
        update(v, pos, tree[last].l,  tree[now].l, l, m);
    } else {
        update(v, pos, tree[last].r,  tree[now].r, m + 1, r);
    }
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

int query(int now, int ql, int qr, int l, int r) {
    if (ql <= l && qr >= r) {
        return tree[now].sum;
    }
    int ans = 0;
    if (ql <= m) ans += query(tree[now].l, ql, qr, l, m);
    if (qr > m) ans += query(tree[now].r, ql, qr, m + 1, r);
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        top = 1;
        scanf("%d %d %d", &n, &mm, &q);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            rt[i] = 0;
            vis[i] = 0;
        }

        for (int i = 1; i <= mm; i++) {
            scanf("%d %d", &e[i].u, &e[i].v);
        }
        for (int i = 1; i <= mm; i++) {
            int fx = find(e[i].u);
            int fy = find(e[i].v);
            if (fx == fy) {
                int pos = min(vis[e[i].u], vis[e[i].v]);
                update(1, pos, rt[i - 1], rt[i], 1, mm);
            } else {
                rt[i] = rt[i - 1];
                fa[fx] = fy;
            }
            vis[e[i].u] = i;
            vis[e[i].v] = i;
        }
        int ans = 0;
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            l = (l ^ ans) % mm + 1;
            r = (r ^ ans) % mm + 1;
            if (l > r) swap(l, r);
            //cout << "l " << l << " r " << r << endl;
            
            if (query(rt[r], l, r, 1, mm)) {
                puts("Yes");
                ans = 1;
            } else {
                puts("No");
                ans = 0;
            }
        }
        for (int i = 0; i < top; i++) {
            tree[i].l = tree[i].r = tree[i].sum = 0;
        }


    }
}


