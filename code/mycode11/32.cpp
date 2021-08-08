#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

const int N = 1e6 + 7;

int n;
ll dp[N][4];

ll dfs(int p, int f) {
    if (p < 1) {
        if (f == 2) {
            return 1;
        }
        return 0;
    }
    if (dp[p][f] != -1) return dp[p][f];
    ll ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (f == 1) {
            if (i == 's') {
                ans = (ans + dfs(p - 1, 2)) % mod;
            } else {
                ans = (ans + dfs(p - 1, f)) % mod;
            }
        } else if (f == 2) {
            ans = (ans + dfs(p - 1, 2)) % mod;
        } else {
            if (i == 'u') {
                ans = (ans + dfs(p - 1, 1)) % mod;
            } else {
                ans = (ans + dfs(p - 1, f)) % mod;
            }
        }
    }
    return dp[p][f] = ans;
}

int main() {
    cin >> n;
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = n; i > 1; i--) {
        ans += dfs(i, 0);
        ans = ans % mod;
    }
    cout << ans << endl;
}