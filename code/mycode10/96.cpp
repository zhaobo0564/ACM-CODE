#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 7;

vector<int> g[N];

int n, m;

int fa[N][30], deep[N];

typedef long long ll;

ll ans[N], x[N], sum[N], len[N], der[N], cat[N];

void dfs(int u, int f) {
    fa[u][0] = f;
    for (int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    deep[u] = deep[f] + 1;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[x] < deep[y]) {
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    for (int i = 0; i <= 20; i++) {
        if ((d & 1 )) {
            x = fa[x][i];
        }
        d = d / 2;
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

void dfs1(int u) {
    for (int to: g[u]) {
        if (to == fa[u][0]) {
            continue;
        }
        dfs1(to);
        x[u] += x[to];
        len[u] += len[to];
        sum[u] += sum[to];
        der[u] += der[to];
        cat[u] += cat[to];
    }
    cat[u] += der[u];
}


void dfs2(int u, ll res) {
    ans[u] = res;
    for (int to: g[u]) {
        if (to == fa[u][0]) {
            continue;
        }
        
        ll cnt = res + 2 * sum[to]  - (len[to] + cat[to]);
        dfs2(to, cnt);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        int lca = get_lca(u, v);
     
        der[u] -= 2, der[v] -= 2;
        der[fa[lca][0]] += 4; 
        cat[u] += 2 * (deep[u] - deep[lca]) + 2;
        cat[v] += 2 * (deep[v] - deep[lca]) + 2;

        int l = deep[u] + deep[v] - 2 * deep[lca];
        len[u] += l - 1, len[v] += l - 1, len[lca] -= (2 * l - 2);
        sum[u] += deep[u] - deep[lca], sum[v] += deep[v] - deep[lca];
        sum[lca] -= (deep[u] - deep[lca] + deep[v] - deep[lca]);
     //   cout << "lca = " << lca << " " << fa[u][1]<< endl;
        if (lca == u || lca == v) continue;
        
        ans[1] += 1ll*(deep[u] - deep[lca]) * 1ll*(deep[v] - deep[lca]);
    }
   // cout << ans[1] << endl;
    dfs1(1);
    dfs2(1, ans[1]);
   // cout << sum[3] << " " << len[3] << " " << cat[3] << " " << der[3] << endl; 
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    
}