#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

vector<int> g[N];

int n, q, deep[N], id[N], sz[N], top = 1, cat[N];

void dfs(int u, int fa) {
    id[u] = top++;
    sz[u] = 1;
    cat[id[u]] = u;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        dfs(to, u);
        sz[u] += sz[to];
    }
}

vector<int> ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        g[x].push_back(i);
    }
    deep[0] = -1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        ans[deep[i]].push_back(id[i]);
    }
    for (int i = 0; i <= n; i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    scanf("%d", &q);
    while (q--) {
        int u, d; scanf("%d %d", &u, &d);
        if (d < deep[u]) {
            puts("0");
        } else {
            int l = id[u], r = id[u] + sz[u] - 1;
            int p = lower_bound(ans[d].begin(), ans[d].end(), l) - ans[d].begin();
            int p1 = upper_bound(ans[d].begin(), ans[d].end(), r) - ans[d].begin();
            printf("%d\n", p1 - p);
        }
    }
    return 0;
}