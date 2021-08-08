#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

ll dp[N][3], sz[N][3];

int head[N], top = 1, n, a[N], b[N], c[N], visa[N], visb[N], visc[N];

struct edge {
    int to, w, nxt;
}e[2 * N];

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}


__int128 ab = 0, ac = 0, bc = 0;
ll ma, mb, mc, sum;

void dfs(int u, int fa) {
    if (visa[u]) {
        sz[u][0] = 1;
    } 
    if (visb[u]) {
        sz[u][1] = 1;
    }
    if (visc[u]) {
        sz[u][2] = 1;
    }
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa) {
            continue;
        }
        dfs(to, u);       
        dp[u][0] += dp[to][0] + sz[to][0] * 1ll * w;
        dp[u][1] += dp[to][1] + sz[to][1] * 1ll * w;
        dp[u][2] += dp[to][2] + sz[to][2] * 1ll * w;

        sz[u][0] += sz[to][0];
        sz[u][1] += sz[to][1];
        sz[u][2] += sz[to][2];
        
    }
}

ll fn[N][3], fz[N][3];

void dfs1(int u, int fa) {

    if (visa[u]) {
        ac += fn[u][2];
        ab += fn[u][1]; 
        
    }
    if (visb[u]) {
        bc += fn[u][2];
        
    }
   

    
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa) continue;
        
        ll sb = fn[u][1] - dp[to][1] - 1ll* w * sz[to][1];
        sb = sb + w * (mb - sz[to][1]);
        fn[to][1] = sb  + dp[to][1];

        ll sc = fn[u][2] - dp[to][2] - 1ll * w * sz[to][2];
        sc = sc + w * (mc - sz[to][2]);
        fn[to][2] = sc + dp[to][2];
        dfs1(to, u); 

    }

}


int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    scanf("%d", &ma);
    for (int i = 1; i <= ma; i++) {
        scanf("%d", &a[i]);
        visa[a[i]] = 1;
    }

    scanf("%d", &mb);
    for (int i = 1; i <= mb; i++) {
        scanf("%d", &b[i]);
        visb[b[i]] = 1;
    }

    scanf("%d", &mc);
    for (int i = 1; i <= mc; i++) {
        scanf("%d", &c[i]);
        visc[c[i]] = 1;
    }
    sum = ma * mb * mc;

    dfs(1, 0);
    fn[1][0] = dp[1][0];
    fn[1][1] = dp[1][1];
    fn[1][2] = dp[1][2];

    dfs1(1, 0);
    __int128 ans = ac * mb + bc * ma + ab * mc;
    ans = ans / 2;
    double res = (double)ans / (double)sum;

    printf("%.9f\n", res);






}