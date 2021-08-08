#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector<pair<int, int>> g[N];

int n, p, k;
vector<int> v;
void dfs(int u, int fa, int sum) {
    if (fa) {
        v.push_back(sum);
    }
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa) continue;
        dfs(to, u, sum + w);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> p >> k;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(p, 0, 0);
    sort(v.begin(), v.end());
    cout << v[k - 1] << endl;
}