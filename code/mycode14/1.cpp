#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
int n, q;

struct point {
    int d[2], id;
    point() {}
    point(int x, int y) {
        this->d[0] = x;
        this->d[1] = y;
    }
} p[N];

struct kd_tree {
    int l, r, d[2], id;
    int maxn[2], minn[2], minn_id;
} tree[N];

#define m (l + r >> 1)

int st;

struct node {
    ll dist, id;
    bool operator < (node x) const {
        if (dist == x.dist) {
            return id < x.id;
        }
        return dist > x.dist;
    }  
};

priority_queue<node> Q;

void push_up(int node) {
    int ls = tree[node].l, rs = tree[node].r;
    for (int i = 0; i < 2; i++) {
        if (ls) {
            tree[node].maxn[i] = max(tree[node].maxn[i], tree[ls].maxn[i]);
            tree[node].minn[i] = min(tree[node].minn[i], tree[ls].minn[i]);
        }
        if (rs) {
            tree[node].maxn[i] = max(tree[node].maxn[i], tree[rs].maxn[i]);
            tree[node].minn[i] = min(tree[node].minn[i], tree[rs].minn[i]);
        }
    }
    if (ls) tree[node].minn_id = min(tree[node].minn_id, tree[ls].minn_id);
    if (rs) tree[node].minn_id = min(tree[node].minn_id, tree[rs].minn_id);
}

int build(int l, int r, int f) {
    st = f;
    nth_element(p + l, p + m, p + r + 1, [](point x, point y) {
        return x.d[st] < y.d[st];
    });
    tree[m].d[0] = tree[m].maxn[0] = tree[m].minn[0] = p[m].d[0];
    tree[m].d[1] = tree[m].maxn[1] = tree[m].minn[1] = p[m].d[1];
    tree[m].id = p[m].id, tree[m].minn_id = p[m].id;
    if (l < m) tree[m].l = build(l, m - 1, f ^ 1);
    if (r > m) tree[m].r = build(m + 1, r, f ^ 1);
    push_up(m);
    return m;
}

ll dist(point x, point y) {
    return 1ll * (1ll * x.d[0] - 1ll * y.d[0]) * 1ll * (1ll * x.d[0] - 1ll * y.d[0]) + 
            1ll * (1ll * x.d[1] - 1ll * y.d[1]) * 1ll * (1ll * x.d[1] - 1ll * y.d[1]);
}

ll work(point x, int id) {
    ll ans = dist(x, point(tree[id].minn[0], tree[id].minn[1]));
    ans = max(ans, dist(x, point(tree[id].minn[0], tree[id].maxn[1])));
    ans = max(ans, dist(x, point(tree[id].maxn[0], tree[id].minn[1])));
    ans = max(ans, dist(x, point(tree[id].maxn[0], tree[id].maxn[1])));
    return ans;
}

void query(point x, int rt) {
    if (!rt) return;
    ll lres = work(x, tree[rt].l);
    ll rres = work(x, tree[rt].r);
    int lid = tree[tree[rt].l].minn_id;
    int rid = tree[tree[rt].r].minn_id;
    ll res = dist(x, point(tree[rt].d[0], tree[rt].d[1]));
    if (res > Q.top().dist) {
        Q.pop();
        Q.push({res, tree[rt].id});
    } else if (res == Q.top().dist) {
        if (tree[rt].id < Q.top().id) {
            Q.pop();
            Q.push({res, tree[rt].id});
        }
    }
    if (lres > rres) {
        if (lres > Q.top().dist) {
            query(x, tree[rt].l);
        } else if (lres == Q.top().dist) {
            if (lid < Q.top().id) {
                query(x, tree[rt].l);
            }
        }
        if (rres > Q.top().dist) {
            query(x, tree[rt].r);
        } else if (rres == Q.top().dist) {
            if (rid < Q.top().id) {
                query(x, tree[rt].r);
            }
        }
    } else {
        if (rres > Q.top().dist) {
            query(x, tree[rt].r);
        } else if (rres == Q.top().dist) {
            if (rid < Q.top().id) {
                query(x, tree[rt].r);
            }
        }
        if (lres > Q.top().dist) {
            query(x, tree[rt].l);
        } else if (lres == Q.top().dist) {
            if (lid < Q.top().id) {
                query(x, tree[rt].l);
            }
        }
    }
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].d[0], &p[i].d[1]);
        p[i].id = i;
    }
    int rt = build(1, n, 0);
    scanf("%d", &q);
    while (q--) {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        while (Q.size()) Q.pop();
        for (int i = 1; i <= k; i++) {
            Q.push({-1, 0});
        }
        query(point{x, y}, rt);
        cout << Q.top().id << endl;

    }
}