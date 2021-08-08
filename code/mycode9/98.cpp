#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n, vis[N], m, dist[N];

vector<int> g[N];

void bfs() {
    queue<int> q;
    q.push(1);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dist[i] = 1e9;
    }
    dist[1] = 0;
    while (q.size()) {
        int cd = q.front();
        q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int to: g[cd]) {
            if (dist[to] > dist[cd] + 1) {
                dist[to] = dist[cd] + 1;
                q.push(to);
            }
        }
    }
}

int dp[N];

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    int ans = dist[u];
    for (int to: g[u]) {
        if (dist[to] > dist[u]) {
            ans = min(ans, dfs(to));
        } else {
            ans = min(ans, dist[to]);
        }
    }
    return dp[u] = ans;
}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << dfs(i) << " ";
    }
    cout << endl;

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}