#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;

vector<int> g[N];

pair<int, int> q[2 * N];

const long long mod = 998344353;

ll cnt[N];
int vis[N];

void bfs() {
    int l = 1, r = 1;
    q[1] = {1, 0};
    while (l <= r) {
        pair<int, int> it = q[l];
        l++;
        if (vis[it.first]) continue;
        vis[it.first] = 1;
        cnt[it.second]++;
        for (int i = 0; i < g[it.first].size(); i++) {
            int to = g[it.first][i];
            q[++r] = {to, it.second + 1};
        }
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    long long ans = 1;
    for (int i = 0; i <= n + 10; i++) {
        if (cnt[i] == 0) break;
        ans = ans * cnt[i];
        ans %= mod;
    }
    printf("%lld\n", ans);

}