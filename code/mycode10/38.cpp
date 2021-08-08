#include<bits/stdc++.h>
using namespace std;

const int N = 200;

struct node {
    int id, to, w;
};

vector<pair<int, int> > cat;

vector<node> g[N];

int d[N], vis[N], del[N], cnt[10];

int dfs(int u) {
    int ans = 0;
    cnt[u] = 1;
    for (auto it: g[u]) {
        if (vis[it.id] || del[it.id]) continue;
        vis[it.id] = 1; 
        ans += dfs(it.to) + it.w;
    }
    return ans;
}
int n; 
bool judge() {
    int ans = 0;
    for (int i = 1; i<= 4; i++) {
        if (cnt[i] && d[i] % 2) {
            ans++;
        }
    }
    if (ans > 2) return false;
    return true;
}

int main() {
  
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> w >> v;
        g[u].push_back({i, v, w});
        g[v].push_back({i, u, w});
        d[u]++, d[v]++;
        cat.push_back({u, v});
        
        
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        int cn = dfs(i);
        if (judge()) {
            ans = max(ans, cn);
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        d[cat[i - 1].first]--;
        d[cat[i - 1].second]--;
        del[i] = 1;
        for (int j = 1; j <= 4; j++) {
            int cn = dfs(j);
            if (judge()) {
                ans = max(ans, cn);
            }
        }        
        d[cat[i - 1].first]++;
        d[cat[i - 1].second]++;
        del[i] = 0;

    }
    cout << ans << endl;
}
