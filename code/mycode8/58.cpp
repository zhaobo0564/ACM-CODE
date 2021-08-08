#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, m;
int a[N], pos[N];

vector<int> g[N];


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }

}


int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}