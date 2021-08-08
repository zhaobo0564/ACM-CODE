#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;

vector<pair<int, int> > g[N];

int n, m, sz[N], maxn[N], rt, Mx, k, q[N], ans[N];
int cnt[10000007], vis[N];
void get_root(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || vis[to]) {
            continue;
        }
        get_root(to, u);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    int Max = max(maxn[u], n - sz[u]);
    if (Mx > Max) {
        Mx = Max;
        rt = u;
    }
}


vector<int> v;
int ok = 0;



vector<int> d;

void dfs(int u, int fa, int dep) {
    d.push_back(dep);
    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (to == fa || vis[to]) continue;
        dfs(to, u, dep + cost);
    }
    
}

vector<int> all;

void gao(int u) {
    vis[u] = 1;
    cnt[0] = 1;
    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (vis[to]) continue;
        d.clear();
        dfs(to, u, cost);

        for (int i = 1; i <= m; i++) {
            if (ans[i]) continue;
            for (int j = 0; j < d.size(); j++) {
                if (d[j] <= q[i]) {
                    if (cnt[q[i] - d[j]]) {
                        ans[i] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < d.size(); i++) {
            all.push_back(d[i]);
            if (d[i] <= 10000000) {
                cnt[d[i]] = 1;
            }
        }

    }

    for (int i: all) {
        if (i <= 10000000) {
            cnt[i] = 0;
        }
    }
    all.clear();

}

void work(int u) {
    gao(u);

    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (vis[to]) continue;
        Mx = 100000;
        n = sz[to];
        get_root(to, 0);
        get_root(rt, 0);
        work(rt);
    }
}

int main() {
    Mx = 1e6;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &q[i]);
    }

    get_root(1, 0);
    get_root(rt, 0);
    work(rt);
    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            puts("AYE");
        } else {
            puts("NAY");
        }
    }



}