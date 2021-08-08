#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int head[N];

struct edge {
    int to, w, nxt;
}e[2 * N];

int top = 1, k, n;

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}
int Mx, rt, sz[N], maxn[N], vis[N];

void get_root(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa || vis[to]) {
            continue;
        }
        get_root(to, u);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (Mx > maxn[u]) {
        Mx = maxn[u];
        rt = u;
    }
}

vector<int> last;
vector<int> now;

void dfs(int u, int fa, int dep) {
    if (dep <= k)
        now.push_back(dep);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa || vis[to]) {
            continue;
        }
        dfs(to, u, dep + w);
        
    }
}

ll ans = 0;

int get_now() {
    sort(now.begin(), now.end());
    int cnt = upper_bound(now.begin(), now.end(), k) - now.begin();
  
    return cnt;
}

int get_ans(int x) {
    int cnt = upper_bound(last.begin(), last.end(), x) - last.begin();
    return cnt;
}

void gao(int u) {
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (vis[to]) continue;
        now.clear();
        dfs(to, u, w);
        ans += get_now();

        for (int j = 0; j < now.size(); j++) {
            ans += get_ans(k - now[j]);
        }

        for (int j: now) {
            last.push_back(j);
        }
        sort(last.begin(), last.end());
    }   
    last.clear();
}

void work(int u) {
    gao(u);

    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (vis[to]) continue;
        Mx = 1000000;
        n = sz[to];
        get_root(to, 0);
        get_root(rt, 0);
        work(rt);

    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        head[i] = 0;
    }
    top = 1;
    ans = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    scanf("%d", &k);
    Mx = 1000000;
    get_root(1, 0);
    get_root(rt, 0);
    work(rt);
    printf("%lld\n", ans);
}
