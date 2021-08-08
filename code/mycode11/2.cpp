#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
#define int long long
int head[N];

struct edge {
    int to, w, nxt;
} e[2 * N];

int top = 1;

int vis[N], cnt[N];

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

ll dp[N][4];

void dfs(int u, int fa) {
    if (vis[u]) cnt[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa) continue;
        dfs(to, u);
        if (cnt[to]) {
            dp[u][0] += dp[to][0] + 1ll * 2 * w;
            if (dp[u][2] < dp[to][0] - dp[to][1] + w) {
                dp[u][3] =max(dp[u][3], dp[u][2]); 
                dp[u][2] = dp[to][0] - dp[to][1] + w;
            } else if (dp[u][3] < dp[to][0] - dp[to][1] + w) {
                dp[u][3] = dp[to][0] - dp[to][1] + w;
            }
        } 
        cnt[u] += cnt[to];
    }
    dp[u][1] = dp[u][0] - dp[u][2];
}

ll ans[N], cat[N];
 
int n, k;

void dfs1(int u, int fa, ll res, ll res1, ll maxn, ll maxn1) {
  //  printf("u = %lld, res = %lld, res1 = %lld, maxn = %lld, maxn1 = %lld\n",u, res, res1, maxn, maxn1);

    ans[u] = res1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa) continue;
        ll dp_fa0 = res - dp[to][0];
        if (cnt[to]) {
            dp_fa0 -= 2 * w;
        }
        ll dp_fa1 = 0;
        if (cnt[to] == 0) {
            dp_fa1 = dp_fa0 - maxn;
        } else if (k == cnt[to]) {
            dp_fa1 = 0;
        }
        else if (maxn == dp[to][0] - dp[to][1] + w) {
            dp_fa1 = dp_fa0 - maxn1;
        } else {
            dp_fa1 = dp_fa0 - maxn;
        }
        ll ans = dp_fa0  + dp[to][0];
        if (k > cnt[to]) ans += 2 * w;
        ll ans1 = 0;
        ll mx = 0, mx1 = 0;
        ll dp_fa2 = dp_fa0 - dp_fa1;
      //  printf("u = %lld, cnt[u] = %lld, dp_fa0 = %lld, dp_fa1 = %lld\n",to, cnt[to], dp_fa0, dp_fa1);

        if (k > cnt[to] && dp_fa2 + w >= dp[to][2]) {
            ans1 = ans - dp_fa2 - w;
            mx = dp_fa2 + w;
            mx1 = dp[to][2];


        } else {
            ans1 = ans - dp[to][2];
            mx = dp[to][2];
            mx1 = dp_fa2;
            if (k > cnt[to]) {
                mx1 += w;
            } 
            mx1 = max(mx1, dp[to][3]);
        }
        dfs1(to, u, ans, ans1, mx, mx1);


    }
}

int32_t main() {
   
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for (int i = 1; i <= k; i++) {
        int x; scanf("%lld", &x);
        vis[x] = 1;
    }
    dfs(1, 0);
    dfs1(1, 0, dp[1][0], dp[1][1], dp[1][2], dp[1][3]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}

/*
9 2
1 2 2
1 7 2
1 3 3
7 8 1
7 9 1
3 4 4
4 5 5
4 6 1
8 9

5
7
8
12
17
13
3
2
2
*/