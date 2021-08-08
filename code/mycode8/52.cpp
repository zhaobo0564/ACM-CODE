#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 7;

vector<pair<int, int> > g[N];

int n, sz[N], son[N], deep[N];
int mod = 300000000;

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto it: g[u])  {
        int to = it.first;
        int cost = it.second;
        if (to == fa) continue;
        deep[to] = (deep[u] + cost) % 3;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

vector<int> cat;
int vis[20];

void work(int u, int fa) {
    cat.push_back(deep[u]);
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa) continue;
        work(to, u);
    }
}

int ans = 0;

vector<int> v;

void cal(int u) {
   // cout << "U = " << u << endl;
    for (int i: cat) {
        int ii = i;
        int cnt = mod - 2 * deep[u];
        cnt = cnt % 3;
        i = i % 3;
        int cn = (i + cnt) % 3;
        ans += vis[(3 - cn) % 3];
        //cout << "I = " << ii << " " << (3 - cn) % 3<<endl;
        //cout << "Ans " << vis[(3 - cn) % 3] << endl;
    }

    for (int i: cat) {
        vis[i]++;
        v.push_back(i);
    }
}

void gao(int u, int fa, int zson) {
    cat.clear();
    cat.push_back(deep[u]);
    cal(u);
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || to == zson) {
            continue;
        }
        cat.clear();
        work(to, u);
        cal(u);

    }

}

void dfs1(int u, int fa, bool ok) {
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || to == son[u]) {
            continue;
        }
        dfs1(to, u, 1);
    }

    if (son[u]) {
        dfs1(son[u], u, 0);
    }
    gao(u, fa, son[u]);
    if (ok) {
        for (int i: v) {
            vis[i] = 0;
        }
      //  cout << "UUU " << u << endl;
        v.clear();
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    ans = ans + ans + n;
    int cnt = n * n;
    int gcd = __gcd(ans, cnt);
    printf("%d/%d\n", ans / gcd, cnt / gcd);
    
}