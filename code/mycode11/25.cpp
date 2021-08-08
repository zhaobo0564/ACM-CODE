#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n, m, a[N], b[N], k;

int vis[N], c[N];
vector<int> g[N];

ll dist[20][N];

queue<int>q;

int cat[N];

void bfs(int s, int id) {
    while (q.size()) q.pop();
    q.push(s);
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        dist[id][i] = 1e9;
    }
    dist[id][s] = 0;
    while (q.size()) {
        int cd = q.front();
        q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        for (int to: g[cd]) {
            if (dist[id][to] > dist[id][cd] + 1) {
                dist[id][to] = dist[id][cd] + 1;
                q.push(to);
            }
        }
    }
}

ll ans = INT_MAX;

int cn[N];

ll dp[20][(1 << 18)];

ll dfs(int p, int stat) {
    if (stat == (1 << k) - 1) {
        return 0;
    }
    if (dp[p][stat] != -1) return dp[p][stat];
    ll ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if ((stat & (1 << (i - 1)))) {

        } else {
            if (dist[p][c[i]] < 1e9) {
                ans = min(ans, dfs(i, stat | (1 << (i - 1))) + dist[p][c[i]]);
            }
        }
    }

    return dp[p][stat] = ans;
   
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);

    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        cat[c[i]] = i;
        bfs(c[i], i);
    }
    
    if (k == 1) {
    
        if (g[c[1]].size() || m == 0) {
            cout << 1 << endl;
            return 0;
        } 
        cout << -1 << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    
    for (int i = 1; i <= k; i++) {
        ans = min(ans, dfs(i, 1 << (i - 1)) + 1);
    }
    if (ans > 1e7) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}