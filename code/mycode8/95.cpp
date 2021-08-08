#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

vector<int> g[N];
int fa[N], n, m, ans[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        int fx = find(u);
        int fy = find(v);
        if (fx == fy) continue;
       
        if (ans[u] == w && ans[v] == w) {
            continue;
        }
        if (ans[u] == w) { 
            fa[fx] = fy;
            ans[v] = w + 1;
            if (ans[v] > n) ans[v] = 1;
        } else if (ans[v] == w) {
            fa[fx] = fy;
            ans[u] = w + 1;
            if (ans[u] > n) {
                ans[u] = 1;
            }
        } else if (ans[u] == 0 && ans[v] == 0) {
            fa[fx] = fy;
            ans[u] = w;
            ans[v] = w + 1;
            if (ans[v] > n) ans[v] = 1;
        } else if (ans[u] == 0) {
            fa[fx] = fy;
            ans[u] = w;
            ans[v] = w + 1;
            if (ans[v] > n) ans[v] = 1;
        } else if (ans[v] == 0) {
            fa[fx] = fy;
            ans[v] = w;
            ans[u] = w + 1;
            if (ans[u] > n) {
                ans[u] = 1;
            }
        }

    }

    set<int> v;
    for (int i = 1; i <= n; i++) {
        int fx = find(i);
        v.insert(fx);
    }
    if (v.size() > 1) {
        cout << "No\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << endl;
        }
    }
}