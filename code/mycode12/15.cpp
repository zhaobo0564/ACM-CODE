#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n;

int vis[N];

vector<pair<int, int> > g[N];

int sz[N], fa[N];
vector<int> v;

void dfs(int u, int f) {
    fa[u] = f;
    sz[u] = 1;
    v.push_back(u);
    for (auto it: g[u]) {
        if (vis[it.second]) continue;
        if (f == it.first) continue;
        dfs(it.first, u);
        sz[u] += sz[it.first];
    }
}

int fn[2000];

bool work(int u, int all) {
    if (all <= 3) return true;
    int ok = 0;
    for (int i = 2; i <= 30; i++) {
        if (fn[i] == all) {
            ok = i;
            break;
        }
    }
    if (ok == 0) return false;
    v.clear();
    dfs(u, 0);
    int pos = 0;
    for (int i: v) {
        if (sz[i] == fn[ok - 1] || sz[i] == fn[ok - 2]) {
            pos = i;
        }
    }
    if (pos == 0) return false;
    for (auto it: g[pos]) {
        if (it.first == fa[pos]) {
            vis[it.second] = 1;
        }
    }
    int y = fa[pos];
    if (sz[pos] == fn[ok - 1]) {
        return work(pos, fn[ok - 1]) && work(y, fn[ok - 2]);
    }
    return work(pos, fn[ok - 2]) && work(y, fn[ok - 1]);


}

int main() {
    fn[0] = 1, fn[1] = 1;
    for (int i = 2; i <= 30; i++) {
        fn[i] = fn[i - 1] + fn[i - 2];
    }

    ios::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    if (work(1, n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}