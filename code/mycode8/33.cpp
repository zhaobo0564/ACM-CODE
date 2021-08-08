#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

int head[N], n, m, q, top = 1, fn[N][30], deep[N];
int dfn[N], id[N];

struct edge{
    int to, nxt;
}e[2 * N];

void add_edge(int u, int v) {
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

int o = 1;

void dfs(int u, int fa) {
    fn[u][0] = fa;
    deep[u] = deep[fa] + 1;
    dfn[u] = o++;
    id[o - 1] = u;
    for (int i = 1; i <= 20; i++) {
        fn[u][i] = fn[fn[u][i - 1]][i - 1];
    }

    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[y] > deep[x]) {
        swap(x, y);
    }
    int d = deep[x] - deep[y];
    int cnt = 0;
    while (d) {
        if (d & 1) {
            x = fn[x][cnt];
        }
        cnt++;
        d = d / 2;
    }

    if (x == y) return x;

    for (int i = 20; i >= 0; i--) {
        if (fn[x][i] != fn[y][i]) {
            x = fn[x][i];
            y = fn[y][i];
        }
    }
    return fn[x][0];
}


vector<int> g[N];

int lca[N], cat[N];

int get_dist(int x, int y, int lc) {

    return deep[x] + deep[y] - 2 * deep[lc];

}


int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int c; scanf("%d", &c);
        for (int j = 1; j <= c; j++) {
            int x; scanf("%d", &x);
            if (j == 1) {
                lca[i] = x;
            } else {
                lca[i] = get_lca(lca[i], x);
            }
            g[i].push_back(dfn[x]);
        }
        sort(g[i].begin(), g[i].end());
    }
    

    scanf("%d", &q);
    while (q--) {
        int u, x; scanf("%d %d", &u, &x);
        int LCA;
        for (int i = 1; i <= x; i++) {
            scanf("%d", &cat[i]);
            if (i == 1) {
                LCA = lca[cat[i]];
            } else {
                LCA = get_lca(LCA, lca[cat[i]]);
            }
        }

        int LC = get_lca(LCA, u);
        int ans = INT_MAX;
        if (LC != LCA) {
            printf("%d\n", get_dist(u, LCA, LC));
        } else {

            for (int i = 1; i <= x; i++) {
                int p = lower_bound(g[cat[i]].begin(), g[cat[i]].end(), dfn[u]) - g[cat[i]].begin();

                if (p == g[cat[i]].size()) {
                    p--;
                    LC = get_lca(u, id[g[cat[i]][p]]);
                    ans = min(ans, get_dist(u, LC, LC));
                }  else {
                    //cout << "U = " << id[g[cat[i]][p]] << endl;
                    LC = get_lca(u, id[g[cat[i]][p]]);
                    ans = min(ans, get_dist(u, LC, LC));
                    if (p) {
                        p--;
                        LC = get_lca(u, id[g[cat[i]][p]]);
                        ans = min(ans, get_dist(u, LC, LC));
                    }
                
                }

               
            }
            printf("%d\n", ans);

        }


    }

}