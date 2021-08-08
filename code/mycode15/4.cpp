#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
typedef long long ll;

vector<pair<int, int> > g[N];

int n, q, dep[N];

vector<ll>sum[N];
vector<int> fn[N];
int fa[N];

int k = 0;

void dfs1(int u, int f) {
    for (auto it: g[u]) {
        int to = it.first;
        if (to == f) continue;
        dep[to] = dep[u] + it.second;
        dfs1(to, u);
    }
}

void dfs(int base, int u, int f, ll deep) {
    fn[base].push_back(deep);
    fa[u] = f;
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == f) continue;
        dfs(base, to, u, deep + w);
    }
}



ll query(int x, ll h) {
    ll ans = 0;
    int y = x;
    while(x != 1) {
        if (x % 2 == 0) {
            int now = x + 1;
            int w = dep[y] - dep[x / 2];
            if (h <= w) {
                x = x / 2;
                break;
            }
            ans += 1ll*(h - w);
            int H = h - w; 
            int W = dep[now] - dep[x / 2];
            if (H <= W) {
                x = x / 2;
                continue;
            }
            int p = lower_bound(fn[now].begin(), fn[now].end(), H - W) - fn[now].begin();
            p--;
            if (p > 0) {
                ans += 1ll * p * 1ll * (H - W) - sum[now][p];
            }

        } else {
            int now = x - 1;
            int w = dep[y] - dep[x / 2];
            if (h <= w) {
                x = x / 2;
                break;
            }
            ans += 1ll*(h - w);
            int H = h - w; 
            int W = dep[now] - dep[x / 2];
            if (H <= W) {
                x = x / 2;
                continue;
            }
            int p = lower_bound(fn[now].begin(), fn[now].end(), H - W) - fn[now].begin();
            p--;
            if (p > 0) {
                ans += 1ll * p * 1ll * (H - W) - sum[now][p];
            }
        }
        x = x / 2;
    }
    int p = lower_bound(fn[y].begin(), fn[y].end(), h) - fn[y].begin();
    p--;
    if (p > 0) {
        ans += 1ll * p * 1ll * h - sum[y][p];   
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int x = 0; scanf("%d", &x);
        
        g[i].push_back({i / 2, x});
        g[i / 2].push_back({i, x});    
    }
    int maxn = 0;
    dfs1(1, 0);

    for (int i = 1; i <= n; i++) {
        fn[i].push_back(-1);
        dfs(i, i, fa[i], 0);
    }
    for (int i = 1; i <= n; i++) {
        sort(fn[i].begin(), fn[i].end());
    }
    for (int i = 1; i <= n; i++) {
        sum[i].resize(fn[i].size());
        for (int j = 1; j < fn[i].size(); j++) {
            sum[i][j] = sum[i][j - 1] + fn[i][j];
        }
    }
    while (q--) {
        int a, h; scanf("%d %d", &a, &h);
        printf("%lld\n", query(a, h));
      
    }

}