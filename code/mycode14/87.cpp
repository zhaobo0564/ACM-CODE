#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e5 + 7;
int a[N * 10], k, n;
int head[N], top;

struct edge {
    int to, nxt, w;
}e[2 * N];

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

int fa[N][30], deep[N];

void dfs(int u, int f, int cost) {
    deep[u] = deep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = head[u]; ~i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f) continue;
        dfs(to, u, i);
    }
}

int get_lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int d = deep[x] - deep[y];
    for (int i = 0; i <= 20; i++) {
        if (d & 1) {
            x = fa[x][i];
        }
        d >>= 1;
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

ll x[N], y[N];
ll fn[N * 10], up[N], down[N];

void work(int u, int f, int UP, int DOWN) {
    up[u] = UP;
    down[u] = DOWN;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        int w1 = e[i ^ 1].w;
        if (to == f) continue;
        work(to, u, w1, w);
        x[u] += x[to];
        y[u] += y[to];
    }     
}



int main() {
    fn[0] = 1;
    for (int i = 1; i < 10 * N; i++) {
        fn[i] = fn[i - 1] * 2 % mod;
    }
    for (int i = 1; i < 10 * N; i++) {
        fn[i] = (fn[i - 1] + fn[i]) % mod;
    }
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        if (w == 1) {
            add_edge(u, v, 0);
            add_edge(v, u, 1);
        } else {
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
       
    }
    scanf("%d", &k);
    a[1] = 1;
    k++;
    for (int i = 2; i <= k; i++) {
        scanf("%d", &a[i]);
    }
    dfs(1, 0, -1);
    for (int i = 2; i <= k; i++) {
        int lca = get_lca(a[i], a[i - 1]);
       // cout << "lca " << lca << endl;   
        x[a[i - 1]]++;
        x[lca]--;
        y[a[i]]++;
        y[lca]--;
    }
    work(1, 0, 0, 0);
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += fn[x[i] - 1] * up[i];
        ans %= mod;
        ans += fn[y[i] - 1] * down[i];
        ans %= mod;
    }
    printf("%lld\n", ans);

}