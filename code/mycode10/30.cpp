#include<bits/stdc++.h>
using namespace std;

const int N = 200;

int mp[N][N], a[N * N], b[N * N], c[N], n, m;

string ans[N * N];

int vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (mp[u][i]) {
            mp[i][u] = 0;
            if (!vis[i]) dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        if (c[a[i]] > c[b[i]]) {
            ans[i] = "->";
        } else if (c[a[i]] < c[b[i]]) {
            ans[i] = "<-";
        } else {
            mp[a[i]][b[i]] = mp[b[i]][a[i]] = 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        dfs(a[i]);
        if (mp[a[i]][b[i]]) {
            ans[i] = "->";
        } else if (mp[b[i]][a[i]]) {
            ans[i] = "<-";
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    
}