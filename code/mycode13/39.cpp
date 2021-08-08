#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, m;

vector<int> g[N];

struct edge{
    int u, v, w;
}e[N];

queue<int> q;

int vis[N], color[N];

bool bfs(int limit) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
        color[i] = -1;
    }

    for (int i = 1; i <= m; i++) {
        if (e[i].w > limit) {
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
        }
    }
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) {
        if (vis[i])continue;
        q.push(i);
        color[i] = 1;
        while (q.size()) {
            int cd = q.front();
            q.pop();
            if (vis[cd]) continue;
            vis[cd] = 1;
            for (int to: g[cd]) {
                if (color[to] == -1) {
                    color[to] = color[cd] ^ 1;
                    q.push(to);
                } else if (color[to] != color[cd]) {
                    q.push(to);
                } else {
                    return false;
                }
            }
        }
    
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    ll l = 1, r = 1000000000, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (bfs(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }

    }
    cout << ans << endl;
    return 0;

}