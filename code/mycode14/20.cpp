#include<bits/stdc++.h>
using namespace std;
const int N = 150007;
typedef long long ll;

int n, q, A;
int  x[N], head[N], top = 1;

struct edge{
    int to, nxt, w;
} e[2 * N];

void add_edge(int u, int v, int w) {
    e[top].to = v;
    e[top].w = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

bool vis[N];
int sz[N], maxn[N], mx, rt;

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

struct node  {
    int fa, id;
    ll dist;        
};

vector<node> fn[N];
vector<pair<ll, ll> > color[N][4];

void dfs(int u, int fa, int dep, int base, int k) {
    fn[u].push_back({base, k, dep});
    color[base][k].push_back({x[u], dep});
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa || vis[to]) continue;
        dfs(to, u, dep + w, base, k);
    }
}

void cal(int u, int k) {
    color[u][k].push_back({A, 0});
    color[u][k].push_back({-1, 0});
    sort(color[u][k].begin(), color[u][k].end());
    for (int i = 1; i < color[u][k].size(); i++) {
        color[u][k][i].second = color[u][k][i - 1].second + color[u][k][i].second;
    }
}

void work(int u) {
    int k = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (vis[to]) continue;
        dfs(to, u, w, u, k);
        cal(u, k);
        k++;
    }
}

void gao(int u) {
    vis[u] = true;
    work(u);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (vis[to]) continue;
        n = sz[to];
        mx = 1e8;
        get_rt(to, u);
        get_rt(rt, 0);
        gao(rt);
    }
}

int getl(int x, int id, int k) {
    int l = 0, r = color[id][k].size() - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (color[id][k][mid].first >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans - 1;
}

int getr(int x, int id, int k) {
    int l = 0, r = color[id][k].size() - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (color[id][k][mid].first <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

ll query(int l, int r, int u) {
    ll res = 0;
    for (int i = 0; i < fn[u].size(); i++) {
        int fa = fn[u][i].fa;
        ll dist = fn[u][i].dist;
        int id = fn[u][i].id;
        if (x[fa] >= l && r >= x[fa]) {
            res += dist;
        }
        for (int j = 0; j < 3; j++) {
            if (color[fa][j].size() == 0) continue;
            if (id == j) continue;
            int pos = getl(l, fa, j);
            int pos1 = getr(r, fa, j);
            ll cnt = pos1 - pos;
            ll ans = color[fa][j][pos1].second - color[fa][j][pos].second;
            res += cnt * dist + ans;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (color[u][j].size() == 0) continue;
        int pos = getl(l, u, j);
        int pos1 = getr(r, u, j);
        res += color[u][j][pos1].second - color[u][j][pos].second;
    }
    return res;
}

int main() {
   scanf("%d %d %d", &n, &q, &A);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    mx = 1e8;
    get_rt(1, 0);
    get_rt(rt, 0);
    gao(rt);
    ll ans = 0;
    while (q--) {
        int u, a, b;
        scanf("%d %d %d", &u, &a, &b);
        int L = min((a + ans) % A, (b + ans) % A);
        int R = max((a + ans) % A, (b + ans) % A);
        ans = query(L, R, u);
        printf("%lld\n", ans);
    }
    return 0;
}

