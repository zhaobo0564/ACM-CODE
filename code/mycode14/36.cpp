#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n;
vector<int> g[N];
int tire[30 * N][2], top = 1;

void insert(int x) {
    int now = 0;
    for (int i = 22; i >= 0; i--) {
        int pos = 0;
        if ((x & (1 << i))) pos = 1;
        if (!tire[now][pos]) {
            tire[now][pos] = top++;
        }
        now = tire[now][pos];
    }
}

int query(int k, int base, int node) {
    if (k < 0) return 0;
    int pos = 0;
    if ((base & (1 << k))) pos = 1;
    if (tire[node][pos ^ 1]) {
        return query(k - 1, base, tire[node][pos ^ 1]) + (1 << k);
    } else {
        return query(k - 1, base, tire[node][pos]);
    } 
}

int sz[N], maxn[N], vis[N], mx;

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

vector<int> cat;

void dfs(int u, int fa, int dep) {
    cat.push_back(dep ^ a[u]);
    for (int to: g[u]) {
        if (vis[to] || to == fa) continue;
        dfs(to, u, dep ^ a[u]);
    }
}

int ans = 0;

void cal(int u) {
    for (int i: cat) {
        int base = a[u] ^ i;
        ans = max(ans, query(22, base, 0));
        ans = max(ans, i);
    }
    for (int i: cat) {
        insert(i);
    }
    cat.clear();
}

void work(int u) {
    ans = max(ans, a[u]);
    for (int to: g[u]) {
        if (vis[to]) continue;
        dfs(to, u, a[u]);
        cal(u);
    }
}

void clear() {
    for (int i = 0; i <= top; i++) {
        tire[i][0] = tire[i][1] = 0;
    }
    top = 1;
}

void gao(int u) {
    n = sz[u];
    mx = 1e8;
    get_rt(u, 0, u);
    get_rt(u, 0, u);
    vis[u] = 1;
    clear();
    work(u);
    for (int to: g[u]) {
        if (vis[to]) continue;
        gao(to);
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    gao(1);
    printf("%d\n", ans);
    
}


