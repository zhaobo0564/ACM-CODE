#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

int head[N], t, n, fa[N];

struct edge {
    int to, nxt;
}e[2 * N];

int top = 1;

void add_edge(int u, int v) {
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}

ll ans = 0;
int dist[N];
int sz[N];

void dfs(int u, int f, int dp) {
    fa[u] = f;
    dist[u] = dp;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f) continue;
        dfs(to, u, dp + 1);
        sz[u] += sz[to];
    }
}

ll maxn = 0;

void dfs1(int u, int f, ll cost) {
    ll cnt = ans - cost + 1ll * (1ll * dist[u] * 1ll *n);
    maxn = max(maxn, cnt);
    
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f) continue;
        dfs1(to, u, cost + 1ll*sz[to]);
    }

}



int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        top = 1;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            head[i] = 0;
            fa[i] = 0;
            dist[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            int x; scanf("%d", &x);
            add_edge(i, x);
            add_edge(x, i);
        }
        ans = 0;
        maxn = 0;
        dfs(1, 0, 1);
        for (int i = 1; i <= n; i++) ans = ans + 1ll*sz[i];
        dfs1(1, 0, 1ll*sz[1]);
        printf("%lld\n", maxn);

        

    }
}