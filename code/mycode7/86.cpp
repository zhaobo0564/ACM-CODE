#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], sz[N], son[N], n, m;

struct query{
    int k, id;
};

vector<query> ans[N];
vector<int> g[N];
int ANS[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int to : g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

int res[N], color[N];

void work(int v, int u, int fa, int zson) {
    
    if (v > 0) {
        color[a[u]]++;
        res[color[a[u]]]++;
    } else {
        res[color[a[u]]]--;
        color[a[u]]--;
    }

    for (int to: g[u]) {
        if (to == fa || to == zson) {
            continue;
        }
        work(v, to, u, zson);
    }
}

void gao(int u) {
    for (int i = 0; i < ans[u].size(); i++) {
        int id = ans[u][i].id;
        int k = ans[u][i].k;
        ANS[id] = res[k];
    }
}



void dfs1(int u, int fa, int ok) {
    for (int to : g[u]) {
        if (to == fa || to ==  son[u]) {
            continue;
        }
        dfs1(to, u, 1);
    }

    if (son[u]) {
        dfs1(son[u], u, 0);
    }

    work(1, u, fa, son[u]);
    gao(u);
    if (ok) {
        work(-1, u, fa, -1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ans[u].push_back({v, i});
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    for (int i = 1; i <= m; i++) {
        cout << ANS[i] << endl;
    }
    
    
}