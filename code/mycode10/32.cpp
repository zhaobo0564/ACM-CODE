#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

map<int, int> mp[N];

int n, c[N], cat[N];

vector<int> g[N];

long long ans[N], maxn[N];

int merge(int x, int y) {
    if (mp[x].size() > mp[y].size()) {
        swap(x, y);
    }
    for (auto it: mp[x]) {
        mp[y][it.first] += it.second;
    }
    mp[x].clear();
    return y;
}

void dfs(int u, int fa) {
    mp[cat[u]][c[u]] = 1;
    maxn[u] = 1;
    ans[u] = c[u];
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        cat[u] = merge(cat[u], cat[to]);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cat[i] = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}