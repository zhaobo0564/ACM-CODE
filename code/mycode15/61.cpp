#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], n;

vector<int> g[N];

void dfs(int u, int fa) {
    for (int i = 0; i < g[u].size(); i++) {
        int to = g[u][i];
        if (to == fa) continue;
        dfs(to, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}