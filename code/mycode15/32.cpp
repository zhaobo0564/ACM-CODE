#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> up;

ll dp[100][2][2];

ll dfs(int p, int limit, int f) {
    if (p >= up.size()) {
        return f % 2;
    }
    if (dp[p][limit][f] != -1) return dp[p][limit][f];
    int maxn = up[p];
    if (!limit) maxn = 1;
    ll ans = 0;
    for (int i = 0; i <= maxn; i++) {
        ans += dfs(p + 1, limit & (i == maxn), (f + i) % 2 );
    }
    return  dp[p][limit][f] = ans;
}

ll work(ll x) {
    up.clear();
    while (x) {
        if (x & 1) {
            up.push_back(1);
        } else {
            up.push_back(0);
        }
        x = x / 2;
    }
    reverse(up.begin(), up.end());
    memset(dp, -1, sizeof(dp));
    return dfs(0, 1, 0);

}


void solve() {
    ll l, r;
    cin >> l >> r;
    r = work(r);
   // cout << r << endl;
    l = work(l - 1);
    printf("%lld\n", r - l);


}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}
