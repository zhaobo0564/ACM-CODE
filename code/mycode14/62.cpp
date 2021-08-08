#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200;
int up[N], top = 1, a[N], m, fn[1000];
ll n;

int f(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x = x / 2;
    }
    return cnt % 2;
}


ll dp[N][2][2][2], cat[2][2][2];

ll work(int all, int ok, int limit) {
    if (cat[all][ok][limit] != -1) return cat[all][ok][limit];
    int sum = limit? n % 128: 127;
    int res = 0;
    for (int i =  0; i <= sum; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            if (i + j >= 128) {
                if ((fn[i + j] ^ all ^ ok) == a[j]) {
                    ans++;
                }
            } else {
                if ((fn[i + j] ^ all) == a[j]) {
                    ans++;
                }
            }
        }
        if (ans == m) {
            res++;
        }
    }
    return cat[all][ok][limit] = res;
}

ll dfs(int p, int all, int ok, int limit) {
    if (p <= 7) {
        return work(all, ok, limit);
    }
    if (dp[p][all][ok][limit] != -1) return dp[p][all][ok][limit];
    int maxn = 1;
    if (limit) maxn = up[p];
    ll ans = 0;
    for (int i = 0; i <= maxn; i++) {
        ans += dfs(p - 1, (all + i) % 2, i == 0? 0: (i + ok) % 2, (i == maxn) & limit);
    }
    return dp[p][all][ok][limit] = ans;
}


void solve() {
    top = 1;
    scanf("%d %lld", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    ll x = n;
    while (x) {
        up[top++] = x % 2;
        x = x / 2;
    }
 
    memset(dp, -1, sizeof(dp));
    memset(cat, -1, sizeof(cat));
    ll ans = dfs(top - 1, 0, 0, 1);
    printf("%lld\n", ans);
 
}


int main() { 
    for (int i = 0; i <= 900; i++) {
        fn[i] = f(i);
    }
  
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}