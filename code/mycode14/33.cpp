#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
string s;
int up[N], n;


pair<ll, ll> dp[N][11][2];

pair<ll, ll> dfs(int p, int eight, int limit) {
    if (p >= n) {
        if (eight == 8) {
            return {1, 0};
        }
        return {0, 0};
    }
    if (dp[p][eight][limit].first != -1) return dp[p][eight][limit];
    int maxn = 9;
    if (limit) maxn = up[p];
    ll ans = 0, cnt = 0;
    for (int i = 0; i <= maxn; i++) {
        auto it = dfs(p + 1, i, maxn == i & limit);
        cnt += it.first;
        cnt %= mod;
        ans += it.first * i % mod;
        ans %= mod;
        ans += it.second;
        ans %= mod;
    }
    return dp[p][eight][limit] = {cnt, ans};
}


int main() {
    
    cin >> s;
    n = s.length();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j][0].first = dp[i][j][1].first = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        up[i] = s[i] - '0';
    }
    auto ans = dfs(0, 0, 1);
    cout << ans.second << endl;
    return 0;

}