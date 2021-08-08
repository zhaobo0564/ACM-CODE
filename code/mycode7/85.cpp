#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int sz[N], son[N], deep[N], ha[N], res[N], ans[N], father[N];

vector<int> g[N];

set<int> v[N];

struct query{
    int h, id;
};

vector<query> q[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]]  < sz[to]) {
            son[u] = to;
        }
    }
}

void work(int f, int u, int fa, int zson) {
    if (f) {
        v[deep[u]].insert(ha[u]);
    } else {
        v[deep[u]].clear();
    }
    for (int to: g[u]) {
        if (to == fa || to == zson) {
            continue;
        }
        work(f, to, u, zson);
    }
}

int cat[N], dog[N];

void gao(int u) {
    for (int i = 0; i < q[u].size(); i++) {
        int id = q[u][i].id;
        int dep = q[u][i].h + deep[u];
        ans[id] = v[dep].size();

    }
    for (int i = 0; i < q[u].size(); i++) {
        dog[q[u][i].id] = 0;
    }
}

void dfs1(int u, int fa, int ok) {
    for (int to: g[u]) {
        if (to == fa || to == son[u]) {
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
        work(0, u, fa, -1);
    }
}   

unordered_map<string, int>vis;
int top = 1;

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string name;
        int u;
        cin >> name >> u;
        if (vis[name] == 0) {
            vis[name] = top;
            ha[i] = top++;
        } else {
            ha[i] = vis[name];
        }
        if (u) {
            g[u].push_back(i);
            father[i] = u;
            

        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        q[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) {
        if (father[i]) continue;

        dfs(i, 0);
        dfs1(i, 0, 1);
    }
 

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    
}