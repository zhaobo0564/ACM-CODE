#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;

ll dp[20][4][2][2][2];

vector<int> up;

ll dfs(int p, int limit, int sum, int one, int two, int ok) {
 
    if (sum == 0) {
        ok = 1;
    } else if (one && (sum - 1 + 3) % 3 == 0) {
        ok = 1;
    } else if (two && (sum - 2 + 3) % 3 == 0) {
        ok = 1;
    }
    
    if (p < 0) {
        return ok;
    }
    if (!limit && dp[p][sum][one][two][ok] != -1) {
        return dp[p][sum][one][two][ok];
    }
    ll ans = 0;
    ll maxn = 9;
    if (limit) {
        maxn = up[p];
    }
    if (sum == 1) {
        one = 1;
    }
    if (sum == 2) {
        two = 1;
    }
    for (int i = 0; i <= maxn; i++) {
        ans += dfs(p - 1, limit && i == maxn, (sum + i) % 3, one, two, ok);
    }
    if (!limit) dp[p][sum][one][two][ok] = ans;
    return ans;
}

ll work(ll x) {
    up.clear();
    while (x) {
        up.push_back(x % 10);
        x = x / 10;
    }
    ll ans = 0;

    for (int i = up.size() - 1; i >= 0; i--) {
        int maxn = up[i];
        int f = 0;
        if (i == up.size() - 1) {
            f = 1;
        } else {
            f = 0;
            maxn = 9;
        }
        for (int j = 1; j <= maxn; j++) {
            ans += dfs(i - 1, f && j == maxn, j % 3, 0, 0, 0);
        }
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while (t--) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", work(r) - work(l - 1));
    }
    return 0;
}