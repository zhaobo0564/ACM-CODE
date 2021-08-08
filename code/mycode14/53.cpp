#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, q, sz[N], vis[N], maxn[N], mx, a[N];

vector<int> g[N];

#define m (l + r >> 1)

struct segment{
    int maxn, pos;
    segment() {
        this->maxn = 0;
        this->pos = 0;
    }
    segment operator +(segment x) {
        segment ans;
        ans.maxn = max(this->maxn, x.maxn);
        if (ans.maxn == this ->maxn) {
            ans.pos = this->pos;
        } else {
            ans.pos = x.pos;
        }
        return ans;
    }
}tree[N * 200];

int o = 1, ls[N * 200], rs[N * 200], rt[N];
int SIZE[N], son[N], k = 1;

void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = o++;
    if (l == r) {
        tree[node].maxn = v;
        tree[node].pos = cat[pos];
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node] = tree[ls[node]] + tree[rs[node]];
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return {-1, -1};
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment ans;
    if (ql <= m) ans = ans + query(ql, qr, l, m, rs[node]);
    if (qr > m) ans = ans + query(ql, qr, m + 1, r, rs[node]);
    return ans;
}


void get_rt(int u, int fa, int &rt) {
    sz[u] = 1;
    maxn[u] = 0;
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        get_rt(to, u, rt);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {
        mx = maxn[u]; 
        rt = u;
    }
}

struct node {
    int fa, dist;
};

vector<node> fn[N];

int top = 2;

vector<int> all, cat[N], cnt[N];

void dfs(int u, int fa, int deep, int base) {
    fn[u].push_back({base, deep});
    all.push_back(u);
    top++;
    if (fa == 0) {
        son[k] = top - 1;
    }
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        dfs(to, u, deep + 1, base);
    }

}

void work(int u) {
    all.clear();
    all.push_back(u);
    top = 2;
    for (int to: g[u]) {
        if (vis[to]) continue;
        dfs(to, u, 1, u);
        k++;
    }
    cat[u].resize(all.size() + 2);
    cnt[u].resize(all.size() + 2);
    for (int i = 0; i < all.size(); i++) {
        cnt[u][all[u][i]] = i + 1;
        cat[u][i + 1] = 
    }

}


void gao(int u) {
    get_rt(u, 0, u);
    get_rt(u, 0, u);
    vis[u] = 1;
    work(u);
    for (int to: g[u]) {
        if (vis[to]) continue;
        gao(to);
    }
}

int fi, se, node;

void dfs1(int u, int fa, int deep) {
    if (mx < deep) {
        mx = deep;
        node = u;
    }
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs1(to, u, deep + 1);
    }
}

int query() {
    if (fi == se && fi != -1) {
        return 0;
    } else if (fi == -1 && se == -1) {
        return -1;
    }
    int x = fi > 0 ? fi : se;
    int ans = 0, node = -1;
    for (int i = 0; i < fn[x].size(); i++) {
        int dist = fn[x][i].dist;
        int fa = fn[x][i].fa;
        if (a[fa] == 0) {
            if (ans <= dist) {
                ans = dist;
                node = fa;
            }
        }
        int res = tree[rt[fa]].maxn, pos = tree[rt[fa]].pos;
    

        
    } 
    
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0, 0);
    fi = node;
    mx = 0;
    dfs1(node, 0, 0);
    se = node;
    gao(1);
    scanf("%d", &q);
    while (q--) {

    }


}