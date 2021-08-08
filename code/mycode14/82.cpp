#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 7;

vector<pair<int, int> > g[N];

int sz[N], maxn[N], mx, vis[N], cnt[N], n; 

void get_rt(int u, int fa, int &rt) {
    sz[u] = 1;
    maxn[u] = 0;
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || vis[to]) continue;
        get_rt(to, u, rt);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {
        mx = maxn[u];
        rt = u;
    }
}

void dfs1(int u, int fa) {
    if (g[u].size() == 1) {
        cnt[u] = 1;
    }
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa) continue;
        dfs1(to, u);
    }
 
}

vector<ll> all, temp; 

void dfs(int u, int fa, int dep) {
    if (cnt[u]) {
        temp.push_back(1ll * dep);
    }
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa || vis[to]) continue;
        dfs(to, u, dep + w);
    }
}

ll counts = 0, sum = 0, sum1 = 0, ans = 0;

void cal() {
    for (ll i: temp) {
        ans += sum + i * i * counts;
        ans += sum1 * i;
    }
    for (ll i: temp) {
        sum += i * i;
        sum1 += i * 2;
        counts++;
    }
    temp.clear();
}

void work(int u) {
    if (cnt[u]) temp.push_back(0);
    cal();
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (vis[to]) continue;
        dfs(to, u, w);
        cal();
    }
    counts = sum = sum1 = 0;
}

void gao(int u) {
    mx = 0;
    get_rt(u, 0, u);
    mx = 1e8;
    n = sz[u];
    get_rt(u, 0, u);
    vis[u] = 1;
    work(u);
    for (auto it: g[u]) {
        int to = it.first;
        if (vis[to]) continue;
        gao(to);
    }
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
 
    dfs1(1, 0);
    gao(1);
    printf("%lld\n", ans);
}