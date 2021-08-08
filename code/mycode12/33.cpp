#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<pair<int, int> > g[N];
int n, k, sz[N], maxn[N], rt, minn, vis[N];

void get_rt(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa || vis[to]) continue;
        get_rt(to, u);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (minn > maxn[u]) {
        minn = maxn[u];
        rt = u;
    }
}

vector<pair<int, int> > cat;
vector<int>all;

void dfs(int u, int fa, int deep, int d) {
    cat.push_back({deep, d});
    all.push_back(deep);
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (to == fa || vis[to]) continue;
        dfs(to, u, deep + w, d + 1);
    }
}

int ans = 10000000;
int cnt[N * 10];

void cal() {
    for (auto i: cat) {
        if (i.first < k) {
            int cn = k - i.first;
            if (cnt[cn]) {
              ans = min(ans, cnt[cn] + i.second);  
            }
            
        } else if (i.first == k) {
            ans = min(ans, i.second);
        }
    }   
    for (auto i: cat) {
        if (i.first > k) continue;
        if (cnt[i.first] == 0) {
            cnt[i.first] = i.second;
        } else {
            cnt[i.first] = min(cnt[i.first], i.second);
        }
    }
}

void work(int u) {
    for (int i: all) {
        if (i > k) continue;
        cnt[i] = 0;
    }
    all.clear();
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (vis[to]) continue;
        cat.clear();
        dfs(to, u, w, 1);
        cal();
    }

}

void solve(int u) {
    vis[u] = 1;
    work(u);
   // cout << u << " ans = " << ans << endl;
    for (auto it: g[u]) {
        int to = it.first;
        if (vis[to]) continue;
        n = sz[to];
        minn = n + 1;
        get_rt(to, u);
        get_rt(rt, 0);
        solve(rt);
    }
}




int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++, v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    minn = n + 1;
    get_rt(1, 0);
    
    get_rt(rt, 0);
    solve(rt);
    printf("%d\n", ans == 10000000 ? -1: ans);
    
}