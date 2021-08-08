#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;

typedef long long ll;

ll a[N], b[N], n, k, m, dp[N];

ll dfs(int sum) {
    if (sum <= 0) {
        return 0;
    }
    ll ans = 0;
    if (dp[sum] != -1) {
        return dp[sum];
    }

    for (int i = 1; i <= n; i++) {
        if (sum >= a[i]) {
            ans = max(ans, dfs(sum - a[i]) + b[i]);
        }
    }
    return dp[sum] = ans;
}

int main() {
    cin >> n >> m >> k;
    ll minn = INT_MAX;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    ll maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        maxn = max(maxn, b[i]);
    }
    ll ans = 0;
    if (k) {
        if (n == 2) {
               if (k % 2) {
                   swap(b[1], b[2]);
               } 
               ans = dfs(m);
        } else {
            while (1) {
                if (m >= minn) {
                    m -= minn;
                    ans += maxn;
                } else {
                    break;
                }
            }
        }
        
    } else {
        ans = dfs(m);
    }
    cout << ans << endl;
}