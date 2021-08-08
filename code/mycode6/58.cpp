#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;


int n, m, fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int fy = find(u), fx = find(v);
        if (fy != fx) {
            fa[fy] = fx;
        }
    }
    set<int> ans;

    for (int i = 1; i <= n; i++) {
        int fy = find(i);
        ans.insert(fy);
    }
    cout << ans.size() - 1 << endl;
}