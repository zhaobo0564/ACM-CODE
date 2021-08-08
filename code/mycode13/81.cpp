#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
struct kd_tree {
    int l, r, d[2], maxn[2], minn[2], id;
}tree[N];

struct point {
    int d[2], id;
    point() {}
    point(int x, int y) {
        d[0] = x;
        d[1] = y;
    }
}p[N];


int st, top = 1;

ll dist(point x, point y) {
    return 1ll*(x.d[0] - y.d[0]) * 1ll * (x.d[0] - y.d[0])  + 1ll * (x.d[1] - y.d[1]) * 1ll * (x.d[1] - y.d[1]);
}


void push_up(int now) {
    int ls = tree[now].l, rs = tree[now].r;
    for (int i = 0; i < 2; i++) {
        if (ls) {
            tree[now].maxn[i] = max(tree[now].maxn[i], tree[ls].maxn[i]);
            tree[now].minn[i] = min(tree[now].minn[i], tree[ls].minn[i]);
        }
        if (rs) {
            tree[now].maxn[i] = max(tree[now].maxn[i], tree[rs].maxn[i]);
            tree[now].minn[i] = min(tree[now].minn[i], tree[rs].minn[i]);
        }
    }
}

priority_queue<ll> q;

ll work(point x, int id) {
    ll res = dist(x, point(tree[id].minn[0], tree[id].minn[1]));
    res = max(res, dist(x, point(tree[id].minn[0], tree[id].maxn[1])));
    res = max(res, dist(x, point(tree[id].maxn[0], tree[id].minn[1])));
    res = max(res, dist(x, point(tree[id].maxn[0], tree[id].maxn[1])));
    return res;
}

int n, k, vis[N];

void query(point x, int now) {
    if (!now) return;
    ll lres = work(x, tree[now].l);
    ll rres = work(x, tree[now].r);
    ll res = dist(x, point(tree[now].d[0], tree[now].d[1]));
    if (!vis[tree[now].id] && -q.top() < res) {
        q.pop();
        q.push(-res);
    }
    if (lres > rres) {
        if (lres > -q.top()) {
            query(x, tree[now].l);
        }
        if (rres > -q.top()) {
            query(x, tree[now].r);
        }
    } else {
        if (rres > -q.top()) {
            query(x, tree[now].r);
        }
        if (lres > -q.top()) {
            query(x, tree[now].l);
        }
    }
   
}

#define m (l + r >> 1)

int build(int l, int r, int f) {
    int now = top++;
    st = f;
    nth_element(p + l, p + m, p + r + 1, [](point x, point y) {
        return x.d[st] < y.d[st];
    });
    tree[now].minn[0] = tree[now].maxn[0] = tree[now].d[0] = p[m].d[0];
    tree[now].minn[1] = tree[now].maxn[1] = tree[now].d[1] = p[m].d[1];
    tree[now].id = p[m].id;
    if (l < m) tree[now].l = build(l, m - 1, f ^ 1);
    if (r > m) tree[now].r = build(m + 1, r, f ^ 1);
    push_up(now);
    return now;
    
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        q.push(1);
    }
    for (int i = 1;  i <= n; i++) {
        scanf("%d %d", &p[i].d[0], &p[i].d[1]);
        p[i].id = i;
    }
    int rt = build(1, n, 0);
    for (int i = 1; i <= n; i++) {
        vis[p[i].id] = 1;
        query(p[i], rt);
    }
   
    cout << -q.top() << endl;
}