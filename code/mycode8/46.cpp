#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int sz[N], son[N], n, dp[N], ans, vis[N * 2], deep[N];
vector<int> g[N];

void dfs(int u,int fa) {
    sz[u] = 1;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        ans = max(ans, dp[to] + 1 + dp[u]);
        dp[u] = max(dp[u], dp[to] + 1);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

vector<int> cat;

void work(int u, int fa) {
    cat.push_back(deep[u]);
    for (int to: g[u]) {
        if (to == fa) continue;
        work(to, u);
    }
}

long long res = 0;

vector<int> v;

void cal(int u) {
    for (int i: cat) {
        if (vis[ans + 2 * deep[u] - i]) {
            res += 1ll * vis[ans + 2 * deep[u] - i];
        }
        v.push_back(i);
    }

    for (int i: cat) {
        vis[i]++;
    }
}

void gao(int u, int fa, int zson) {
    v.push_back(deep[u]);
    cat.clear();
    cat.push_back(deep[u]);
    cal(u);
    for (int to: g[u]) {
        if (to == fa || to == zson) {
            continue;
        }
        cat.clear();
        work(to, u);
        cal(u);
    }
}

void dfs1(int u, int fa, bool ok) {
    for (int to: g[u]) {
        if (to == fa || to == son[u]) {
            continue;
        }
        dfs1(to, u, 1);
    }
    if (son[u]) {
        dfs1(son[u], u, 0);
    }

    gao(u, fa, son[u]);
    
    if (ok) {
        for (int i: v) {
            vis[i] = 0;
        }
        v.clear();
    }


}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    cout << res + res << endl;
}