#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, a[N];

vector<int> g[N];

void build(int l, int r, int root) {
    if (l > r) return;
    if (l == r) {
    //    cout << root << " " << a[l] << endl;
        g[root].push_back(a[l]);
        return;
    }
    int maxn = 0, pos;
    for (int i = l; i <= r; i++) {
        if (a[i] > maxn) {
            maxn = a[i];
            pos = i;
        }
    }
  //  cout << root << " " << maxn << endl;

    g[root].push_back(maxn);
    build(l, pos - 1, maxn);
    build(pos + 1, r, maxn);
}

int deep[N];
void dfs(int u, int fa) {
  //  cout << "u " << u << endl;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        dfs(to, u);
    }
}

void solve() {
    cin >> n;
    int maxn = 0, pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > maxn) {
            maxn = a[i];
            pos = i;
        }
        g[a[i]].clear();
        deep[a[i]] = 0;
    }
    deep[0] = 0;
    build(1, pos - 1, maxn);
    build(pos + 1, n, maxn);
    dfs(maxn, 0);
    for (int i = 1; i <= n; i++) {
        cout << deep[a[i]] - 1 << " ";
    }
    cout << endl;

    




    
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }    
}