#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long ll;
vector<int> g[N];

ll a[N], n, q;

ll ans = 0;
int fa[N];
void dfs(int u, int f) {
    fa[u] = f;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
    }
}

void dfs1(int u, int f) {
    ans += a[u];
    for (int to: g[u]) {
        if (to == f) continue;
        dfs1(to, u);
    }
}

void dfs2(int v, int u, int f) {
    a[u] += v;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs2(v, to, u);
    }
}

int main() {
    // freopen("in.in", "r", stdin);   //只改变输入流的文件指针，读入这个文件的内容（必须要有input这个文件）stdin是标准输入流的文件指针
	// freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u; cin >> u;
            ans = 0;
            dfs1(u, fa[u]);
            cout << ans << endl;
        } else if (op == 2) {
            int u, v; cin >> u >> v;
            dfs2(v, u, fa[u]);
        } else {
            int u, v; cin >> u >> v;
            a[u] += v;
            for (int to: g[u]) {
                if (to == fa[u]) continue;
                a[to] += v;
            }
        }
    }
}