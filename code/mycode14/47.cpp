#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<int> g[N];
int a[N], sz[N], maxn[N], mx, n, q;

void get_rt(int u, int fa, int &rt) {
    sz[u] = 1;
    maxn[u] = 0;
    for (int to: g[u]) {
        if (to == fa) continue;
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

struct BIT {
    vector<int> sum;
    int n;
    void init(int n) {
        this->n = n;
        sum.resize(n + 10);
    }
    int lowbit(int x) {return (x & -x);}
    void add(int x, int v) {
        while (x <= n) {
            sum[x] += v;
            x += lowbit(x);
        }
    }  
    int query(int l) {
        int ans = 0;
        while (l > 0) {
            ans += sum[l];
            l -= lowbit(l);
        }
        return ans;
    }
} tree[N], tree1[N];

struct node {
    int fa, dist, son;
};

vector<node> fn[N];
vector<int> all[N], SON[N];
int son[N], All[N];

int k = 0, vis[N];



void dfs(int u, int fa, int deep, int base) {
    son[deep] += a[u];
    fn[u].push_back({base, deep, k});
    SON[k].push_back(deep - 1);
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        dfs(to, u, deep + 1, base);
    }
}

void cal(int u) {
    sort(SON[k].begin(), SON[k].end());
    SON[k].erase(unique(SON[k].begin(), SON[k].end()), SON[k].end());
    for (int i: SON[k]) {
        all[u].push_back(i);
        All[i] += son[i];
    }
    tree1[k].init(SON[k].size());
    for (int i = 0 ; i < SON[k].size(); i++) {
        tree1[k].add(i + 1, son[SON[k][i]]);
        son[i] = 0;
    }
}

void work(int u) {
    all[u].push_back(0);
    All[0] += a[u];
    for (int to: g[u]) {
        if (vis[to]) continue;
        k++;
        dfs(to, u, 1, u);
        cal(u);
    }
    sort(all[u].begin(), all[u].end());
    all[u].erase(unique(all[u].begin(), all[u].end()), all[u].end());
    tree[u].init(all[u].size());
    for (int i = 0; i < all[u].size(); i++) {
        tree[u].add(i + 1, All[all[u][i]]);
        All[i] = 0;
    }
}

void gao(int u) {
    n = sz[u];
    mx = 1e8;
    get_rt(u, 0, u);
    get_rt(u, 0, u);
    vis[u] = 1;
    work(u);
    for (int to: g[u]) {
        if (vis[to]) continue;
        gao(to);
    }
}

int query(int x, int y) {
    int ans = 0;
    for (int i = 0; i < fn[x].size(); i++) {
        int son = fn[x][i].son;
        int fa = fn[x][i].fa;
        int dist = fn[x][i].dist;
        if (dist > y) break;
        int cnt = y - dist;
        int p = upper_bound(all[fa].begin(), all[fa].end(), cnt) - all[fa].begin();
        int p1 = upper_bound(SON[son].begin(), SON[son].end(), cnt) - SON[son].begin();
        ans += tree[x].query(p) - tree1[son].query(p1);
    }
    int p = upper_bound(all[x].begin(), all[x].end(), y) - all[x].begin();
    ans += tree[x].query(p);
    return ans;
} 

void update(int x, int y) {
    int p = upper_bound(all[x].begin(), all[x].end(), 0) - all[x].begin();
    tree[x].add(p, -a[x] + y);
    for (int i = 0; i < fn[x].size(); i++) {
        int son = fn[x][i].son;
        int fa = fn[x][i].fa;
        int dist = fn[x][i].dist;        
        p = upper_bound(all[fa].begin(), all[fa].end(), dist) - all[fa].begin();
        tree[fa].add(p, -a[x] + y);
        p = upper_bound(SON[son].begin(), SON[son].end(), dist - 1) - SON[son].begin();
        tree1[son].add(p, -a[x] + y); 
    }
    a[x] = y;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    gao(1);
    while (q--) {
        int op, x, y; scanf("%d %d %d", &op, &x, &y);
        if (op == 0) {
            printf("%d", query(x, y));
        } else {
            update(x, y);
        }
    }

}