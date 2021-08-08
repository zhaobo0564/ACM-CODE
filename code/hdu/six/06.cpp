#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;

ll fn[N];

struct edge{
    int u, v, w;
}e[N];


int t, n, m, a[N], fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

vector<pair<int, int> >g[N];

ll ans = 0;

ll dp[N][2], f[N];

int vis[N];

ll one = 0, zero= 0;


void dfs(int u, int fa) {
    vis[u] = 1;
    dp[u][a[u]] = 1;
    if (a[u]) {
        one++;
    } else {
        zero++;
    }
    for (auto it: g[u]) {
        int to = it.first;
        ll cost = fn[it.second];
        if (to == fa) continue;
        dfs(to, u);
        dp[u][1] += dp[to][1];
        dp[u][0] += dp[to][0];
    }
}

void dfs1(int u, int fa) {
    for (auto it: g[u]) {
        int to = it.first;
        ll cost = fn[it.second];
        if (to == fa) continue;
        dfs1(to, u);
        ll down0 = dp[to][0];
        ll up1 = one - dp[to][1];
        ans = (ans + (((down0 % mod * up1 % mod) * cost % mod)%mod) % mod) % mod;
        ll down1 = dp[to][1];
        ll up0 = zero - dp[to][0];
        ans = (ans + (((down1 % mod * up0 % mod) * cost % mod)%mod) % mod) % mod;

    }
}


int main() {
  //  freopen("1.in", "r", stdin);   
//	freopen("output.txt", "w", stdout); 
    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            fa[i] = i;
            dp[i][0] = dp[i][1] = 0;
            vis[i] = 0;
            g[i].clear();

        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int fy = find(u);
            int fx = find(v);
            if (fx != fy) {
                fa[fx] = fy;
                g[u].push_back({v, i});
                g[v].push_back({u, i});
            }
            
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                one = zero = 0;
                dfs(i, 0);
                dfs1(i, 0);
            }
        }
        printf("%lld\n", ans);
    }
}
