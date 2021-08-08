#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll son[N], sz[N], n, a[N], color[N];
ll ans[N];

vector<int> g[N];

void dfs(int u, int f) {
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

ll maxn = 0, sum;

void work(int v, int u, int f, int zson) {
    color[a[u]] += v;
    if (color[a[u]] > maxn) {
        maxn = color[a[u]];
        sum = a[u];
    } else if (color[a[u]] == maxn) {
        sum += a[u];
    }

    for (int to: g[u]) {
        if (to == f || to == zson) {
            continue;  
        } 
        work(v, to, u, zson);
    }

}

void dfs1(int u, int f, bool ok) {

    for (int to: g[u]) {
        if (to == f || to == son[u]) continue;
        dfs1(to, u, 1);
    }

    if (son[u]) {
        dfs1(son[u], u, 0);
    }
    
    work(1, u, f, son[u]);
    ans[u] = sum;
    if (ok == 1) {
        work(-1, u, f, -1);
        sum = 0;
        maxn = 0;
    }

}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    dfs1(1, 0, -1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;



}