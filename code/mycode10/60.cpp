#include<bits/stdc++.h>
using namespace std;

const int N = 207;

int mp[N][N], n, m, R;

int r[N];

vector<int> g;

vector<pair<int, int> > G[N];

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin();
}

bool judge(int x) {
    int count = 0;

    while (x) {
        if (x & 1) {
            count++;
        }
        x = x / 2;
    }
    return count == R;
}

int dp[16][1 << 16];

int dfs(int u, int stat) {
    if (judge(stat)) {
        return 0;
    }
    int ans = 1e8;
   // if (dp[u][stat] != -1) return dp[u][stat];
    for (auto it: G[u]) {
        int to = it.first;
        int w = it.second;
        if (((1 << to) & stat)) {

        } else {
           // cout << "W " << w << endl;
            ans = min(ans, dfs(to, stat + (1 << to)) + w);
        }
    }
    return dp[u][stat] = ans;
}

int main() {
    cin >> n >> m >> R;
    for (int i = 1; i <= R; i++) {
        cin >> r[i];
        g.push_back(r[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = mp[j][i] = 1e8;
            mp[i][i] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
    }
   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                mp[j][k] = min(mp[j][k], mp[j][i] + mp[i][k]);
                
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= R; j++) {
            if (i == j || mp[i][j] == 1e8) continue;
            int u = get_id(r[i]), v = get_id(r[j]);
         //   cout << r[i] << " " << r[j] << " " << mp[r[i]][r[j]] << endl;
            G[u].push_back({v, mp[r[i]][r[j]]});
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 1e8;
    for (int i = 0; i < R; i++) {
        ans = min(ans, dfs(i, 1 << i));
    }

    cout << ans << endl;
}