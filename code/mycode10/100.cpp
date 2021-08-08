#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
const ll mod = 1e9 + 7;
int head[N], top = 1;

struct edge{
    int to, nxt;
}e[2 * N];

void add_edge(int u, int v) {
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

ll dp[N];

void dfs(int u, int fa) {
    dp[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa) continue;
        dfs(to, u);
        dp[u] += (dp[u] % mod * dp[to] % mod) % mod;
        dp[u] %= mod;
    }
}

ll ans[N];

ll inv;

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base % mod;
}

void dfs1(int u, int fa, ll res) {
    ans[u] = res;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa) continue;
        if ((dp[to] + 1) % mod == 0) {
            ll cnt = 1;
            for (int j = head[u]; j; j = e[j].nxt) {
                int t = e[j].to;
                if (t == fa || t == to) continue;
                cnt += cnt * dp[t] % mod;
                cnt = cnt % mod;
            }
            ll cn =(dp[to] + (cnt % mod  * dp[to] % mod) % mod) % mod;
            dfs1(to, u, cn);
        } else {
            ll cnt = (res % mod * ksm(dp[to] + 1, mod - 2) % mod) % mod;
            ll cn =(dp[to] + (cnt % mod  * dp[to] % mod) % mod) % mod;
            
            dfs1(to, u, cn);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    dfs1(1, 0, dp[1]);
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }

}