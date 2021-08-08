#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 9;
ll n, r[20], dp[70][2050];
#define int long long

ll dfs(int p, int s) {
    if (p < 0) return 1;
    if (dp[p][s] != -1) return dp[p][s];
    ll ans = 0;
    int now = s;
    for (int i = 1; i <= n; i++) {
        if (r[i] & (1ll << p)) {
            now |= (1ll << i);
            
        }
    }
    ans = ans +  dfs(p - 1, now);
    ans %= mod;
    for (int i = 1; i <= n; i++) {
        if (s & (1ll << i)) {
            ans = ans + dfs(p - 1, now);
            ans = ans % mod;
        } else if (now & (1ll << i)) {
            ans = ans + dfs(p - 1, now ^ (1ll << i));
            ans = ans % mod;
        }
    }
    dp[p][s] = ans;
    return ans;
    
}

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(61, 0) << endl;
}

