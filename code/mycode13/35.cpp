#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

typedef long long ll;
vector<pair<int, int> > g[N];
ll n, k;
ll dp[N][N], temp[N], sz[N];

void dfs(int u, int fa, ll cost) {
    sz[u] = 1;
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs(to, u, w);

        for (ll i = 0; i <= sz[u]; i++) {
            for (ll j = 0; j <= sz[to]; j++) {
                if (i + j > k) break;
                ll val = j * (k - j) * w + (sz[to] - j) * (n - k - sz[to] + j) * w;
                temp[i + j] = max(temp[i + j], dp[u][i] + dp[to][j] + val);

            }
        }

        for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[to]; j++) {
                if (i + j > k) break;
                dp[u][i + j] = max(dp[u][i + j], temp[i + j]);
                temp[i + j]= 0;
            }
        }
        sz[u] += sz[to];
    }

    

    
}

int main() {
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    cout << dp[1][k] << endl;
}


