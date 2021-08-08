#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

vector<int> g[N];

int n, a, b, da, db;

int d;

void dist(int u, int fa, int dp) {
    if (u == b) {
        d = dp;
        return;
    }   

    for (int to: g[u]) {
        if (to == fa) continue;
        dist(to, u, dp + 1);
    }
}

int ans = 0, dp[N];

void dfs(int u, int fa) {
    for (int to : g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        ans = max(ans, dp[u] + dp[to] + 1);
        dp[u] = max(dp[u], dp[to] + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dp[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dist(a, 0, 0);
      //  cout << d << endl;
        if (da >= d) {
            cout << "Alice\n";

        } else {
            dfs(1, 0);
            if (db > 2 * da && ans > 2 * da) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
      

        

    }
}