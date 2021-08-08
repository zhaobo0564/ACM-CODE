#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int a[N], n, q;
vector<int> g[N];

int sz[N], maxn[N], mx, vis[N];

struct node {
    int fa, dist, son;
};

vector<node> fn[N];

struct BIT{
    vector<int> sum;
    int n;
    void init(int n) {
        sum.resize(n + 10);
        this->n = n + 2;
    }
    int lowbit(int x) {
        return (x & (-x));
    }
    void add(int x, int v) {
        while (x <= n) {
            sum[x] += v;
            x += lowbit(x);
        }
    }
    int ask(int x) {
        int ans = 0;
        while (x > 0) {
            ans += sum[x];
            x -= lowbit(x);
        }
        return ans;
    }
} tree[N], tree1[N];


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

vector<int> all[N], son[N], temp;

int color[N], SON[N], o = 1;


void dfs(int u, int fa, int deep, int base) {
    fn[u].push_back({base, deep, o});
    son[o].push_back(deep - 1);
    SON[deep] += a[u];
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        dfs(to, u, deep + 1, base);
    }
}

void cal(int u) {
 //   cout << "u = " << u << endl;
    sort(son[o].begin(), son[o].end());
    son[o].erase(unique(son[o].begin(), son[o].end()), son[o].end());
    tree1[o].init(son[o].size());
    for (int i = 0; i < son[o].size(); i++) {
       // cout << "dd " << SON[son[o][i] + 1] << endl;
        color[son[o][i] + 1] += SON[son[o][i] + 1];
        all[u].push_back(son[o][i] + 1);
        tree1[o].add(i + 1, SON[son[o][i] + 1]);
        SON[son[o][i] + 1] = 0;
    }
    o++;
}

void work(int u) {
    all[u].push_back(0);
    color[0] = a[u];
    for (int to: g[u]) {
        if (vis[to]) continue;
        dfs(to, u, 1, u);
        cal(u);
    }
    sort(all[u].begin(), all[u].end());
    all[u].erase(unique(all[u].begin(), all[u].end()), all[u].end());
    tree[u].init(all[u].size());
    for (int i = 0; i < all[u].size(); i++) {
        tree[u].add(i + 1, color[all[u][i]]);
        color[all[u][i]] = 0;
    }
}

void gao(int u) {
    get_rt(u, 0, u);
    n = sz[u];  
    mx = 1e8;
    get_rt(u, 0, u);
    vis[u] = 1;
    work(u);
    for (int to: g[u]) {
        if (vis[to]) continue;
        gao(to);
    }
}

void update(int x, int y) {
    int p = upper_bound(all[x].begin(), all[x].end(), 0) - all[x].begin();
    tree[x].add(p, y - a[x]);
    for (int i = 0; i < fn[x].size(); i++) {
        int id = fn[x][i].son;
        int dist = fn[x][i].dist;
        int fa = fn[x][i].fa;
        p = upper_bound(all[fa].begin(), all[fa].end(), dist) - all[fa].begin();
        tree[fa].add(p, y - a[x]);
        int p1= upper_bound(son[id].begin(), son[id].end(), dist - 1) - son[id].begin();
        tree1[id].add(p1, y - a[x]);
    }
    a[x] = y;
}

int query(int x, int y) {
    int ans = 0;
    for (int i = 0; i < fn[x].size(); i++) {
        int fa = fn[x][i].fa;
        int id = fn[x][i].son;
        int dist = fn[x][i].dist;
        if (dist > y) continue;
        if (dist == y) {
            ans += a[fa];
            continue;
        }
        int cnt = y - dist;
        int p = upper_bound(all[fa].begin(), all[fa].end(), cnt) - all[fa].begin();
        ans += tree[fa].ask(p);
        p = upper_bound(son[id].begin(), son[id].end(), cnt - 1) - son[id].begin();
        ans -= tree1[id].ask(p);
    }
    int p = upper_bound(all[x].begin(), all[x].end(), y) - all[x].begin();
    ans += tree[x].ask(p);
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    gao(1);

    int last = 0;
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        x = x ^ last;
        y = y ^ last;
        if (op == 0) {
            last = query(x, y);
            printf("%d\n", last);
        } else {
            update(x, y);
        }
    }
    return 0;

}