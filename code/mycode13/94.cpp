#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, k, head[N];
const ll mod = 998244353;

struct edge{
    int to, nxt, w;
}e[2 * N];

int top = 1;

typedef long long LL;

LL c[61][61];
void C()
{
    int i,j;
    for(i=0;i<60;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<60;i++)
        for(j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1], c[i][j] %= mod;
}

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

int vis[N], sz[N], maxn[N], rt, mx;

void get_rt(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa || vis[to]) continue;
        get_rt(to, u);
        sz[u] += sz[to]; 
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {
        mx = maxn[u];
        rt = u;
    }
}

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x;
            base %= mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

ll dp[20], all[20];

void dfs(int u, int fa, ll dep) {
    for (int i = 0; i <= k; i++) {
        dp[i] += ksm(dep, i);
        dp[i] %= mod;
    }
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        ll w = e[i].w;
        if (to == fa || vis[to]) continue;
        dfs(to, u, dep + w);
    }
}
ll ans = 0;

void cal() {
    ans += dp[k];
    ans %= mod;
    for (int i = 0; i <= k; i++) {
        ll cnt = c[k][i] * dp[i] % mod;
        cnt = cnt * all[k - i];
        cnt %= mod;
        ans += cnt;
        ans %= mod;
    }
    for (int i = 0; i <= k; i++) {
        all[i] += dp[i];
        all[i] %= mod;
    }
}


void solve(int u, int fa) {
    for (int i = 0; i <= k; i++) {
        all[i] = 0;
    }
   // cout << "u " << u << endl;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        ll w = e[i].w; 
       // cout << "to " << to << endl;
        if (to == fa || vis[to]) continue;
        for (int j = 0; j <= k; j++) {
            dp[j] = 0;
        }
       
        dfs(to, u, w);
        cal();
        //cout << "ans " << ans << endl;
    }
}

void gao(int u) {
    vis[u] = 1;
    solve(u, 0);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (vis[to]) continue;
        mx = 1e8;
        n = sz[to];
        get_rt(to, u);
        get_rt(rt, 0);
        gao(rt);
    }
}


int main() {
    C();
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    ll inv = ksm(1ll * n * n, mod - 2);
    mx = 1e8;
    get_rt(1, 0);
    get_rt(rt, 0);
    gao(rt);
    ans = (ans + ans) % mod;
    ans = ans * inv % mod;

    cout << ans << endl;
}