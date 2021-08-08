#include<bits/stdc++.h>
using namespace std;
const int N = 507;
typedef long long ll;
int n, m, k, a[N][N], b[N][N];

vector<pair<int, int> > g[N * N];

int cnt[N][N], top = 1, base;
ll dp[N * N][22];




ll dfs(int p, int sum) {
   
    if (sum == 0 ) return 0;
    if (sum == 0) return INT_MAX;
    if (dp[p][sum] != -1) return dp[p][sum];
    ll ans = INT_MAX;
    for (int i = 0; i < g[p].size(); i++) {
        int to = g[p][i].first;
        ll w = 1ll * g[p][i].second;
    
        ans = min(ans, dfs(to, sum - 1) + w * 2);
    }
    return dp[p][sum] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[i][j] = top++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> a[i][j];
            g[cnt[i][j]].push_back({cnt[i][j + 1], a[i][j]});
            g[cnt[i][j + 1]].push_back({cnt[i][j], a[i][j]});
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            g[cnt[i][j]].push_back({cnt[i + 1][j], b[i][j]});
            g[cnt[i + 1][j]].push_back({cnt[i][j], b[i][j]});
        }
    }
    if (k % 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            base = cnt[i][j];
            ll ans = dfs(cnt[i][j], k / 2);
            if (ans >= INT_MAX) {
                cout << -1 << " ";
            } else {
                cout << ans << " ";
            }
        }
        cout << endl;
    }
   
}