#include<bits/stdc++.h>
using namespace std;
const int N = 5007;

int dist[N], n, q, vis[N], m;

vector<int> v;
vector<int> g[N];

void bfs() {
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        dist[i] = 1e7;
    }
    queue<int> q;
    for (int i: v) {
        dist[i] = 0;
        q.push(i);
    }
    while (q.size()) {
        int cd = q.front();
        q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int to: g[cd]) {
            if (dist[to] > dist[cd] + 1) {
                dist[to] = dist[cd] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (q--) {
        int t, s;
        scanf("%d %d", &t, &s);
        v.clear();
        for (int i = 1; i <= t; i++) {
            int x; scanf("%d", &x);
            v.push_back(x);
        }
        bfs();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            //cout << "dist " << dist[i] << endl;
            if (dist[i] <= s) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}