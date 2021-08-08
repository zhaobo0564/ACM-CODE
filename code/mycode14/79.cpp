#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n, s;
ll dp[N][2];

vector<int> g[N];

void dfs(int u, int fa) {
    vector<int> v;
    for (int to: g[u]) {
        if (to == fa) continue;
        if (dp[to][1]) {
            dp[to][0]++;
            dp[to][1]--;
            dfs(to, u);
            v.push_back(to);

        }
    }
    sort(v.begin(), v.end(), [] (int x, int y) {
        return dp[x][0] > dp[y][0];
    });
    for (int i = 0; i < v.size(); i++) {
        if (dp[u][1]) {
            dp[u][1]--;
            dp[u][0] += dp[v[i]][0] + 1;
        } else if (dp[u][1] == 0) {
            break;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (dp[u][1]) {
            ll cnt = min(dp[u][1], dp[v[i]][1]);
            dp[u][0] += cnt * 2;
            dp[u][1] -= cnt;
            dp[v[i]][1] -= cnt;
        }
    }

}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dp[i][1]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &s);
    dfs(s, 0);
    printf("%lld\n", dp[s][0]);
}