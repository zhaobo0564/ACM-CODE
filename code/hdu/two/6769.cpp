#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int n, k, t, sz[N];

ll dp[N][30];

struct node{
    int v;
    ll a, b;
};

vector<node>g[N];

ll ans = 0;

void dfs(int u, int fa, ll limit) {

    for (auto it: g[u]) {
        int to = it.v;
        ll a = it.a;
        ll b = it.b;
        if (to ==  fa) continue;
        dfs(to, u, limit);

        ll fn[22] = {0};

        for (int i = 1; i <= k; i++) {
            if (dp[u][i] <= limit) {
                fn[i] = max(fn[i - 1], dp[u][i]);
            }
        }

        for (int i = k; i >= 0; i--) {
            if (fn[k - i] + dp[to][i] + b <= limit) {
                ans = max(fn[k - i] + dp[to][i] + b, ans);
            }
            if (i - 1 >= 0 &&fn[k - i] + dp[to][i - 1] + a <= limit) {
                ans = max(fn[k - i] + dp[to][i - 1] + a, ans);
            }
            if (k - i - 1 >= 0 && fn[k - i - 1] + dp[to][i] + a <= limit) {
                ans = max(fn[k - i - 1] + dp[to][i] + a, ans);
            }
        }


        for (int i = 1; i <= k; i++) {
           if (dp[to][i] + b <= limit) {
               dp[u][i] = max(dp[u][i], dp[to][i] + b);
           }
           if (dp[to][i - 1] + a <= limit) {
               dp[u][i] = max(dp[u][i], dp[to][i - 1] + a);
           }
        }    
    }
} 

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i < n; i++) {
            int u, v;
            ll a, b;
            scanf("%d %d %lld %lld", &u, &v, &a, &b);
            g[u].push_back({v, a, b});
            g[v].push_back({u, a, b});
        }
        dfs(1, 0, 8);
        cout << ans << endl;
    }
}
