#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

typedef long long ll;

ll sz[N], ans;

vector<int> g[N];

void dfs(int u, int fa, ll dep) {
    ans += dep;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        dfs(to, u, dep + 1);
        sz[u] += sz[to];
    }
}
ll minn, n;

void dfs1(int u, int fa, ll cost) {
    minn = min(minn, cost);
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs1(to, u, cost - sz[to] + (n - sz[to]));
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    minn = LLONG_MAX;
    dfs(1, 0, 0);
    dfs1(1, 0, ans);
    cout << minn << endl;
}