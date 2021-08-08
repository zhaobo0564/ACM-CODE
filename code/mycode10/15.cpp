#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k, q, a[N], dp[N][N][2];
ll sum[N], fn[N][N];

ll dfs(int p, int sum) {
    
    if (sum == 0) {
        if (fn[p][sum] == -1) fn[p][sum] = 1;
        else fn[p][sum]++;
        return  1;
    }
    if (fn[p][sum] != -1) return fn[p][sum];
    ll ans = 0;
    if (p < n) {
        ans += dfs(p + 1, sum - 1);
    }
    if (p > 1) {
        ans += dfs(p - 1, sum - 1);
    }
    ans %= mod;
    return fn[p][sum] = ans;
}


int main() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0][0] = a[i];
        dp[i][0][1] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                dp[j][i][0] = dp[j + 1][i - 1][0] + dp[j + 1][i - 1][1] * a[j]; 
                dp[j][i][1] = dp[j + 1][i - 1][1];
            } else if (j == n) {
                dp[j][i][0] = dp[j - 1][i - 1][0] + dp[j - 1][i - 1][1] * a[j]; 
                dp[j][i][1] = dp[j - 1][i - 1][1];
            } else  {
                dp[j][i][0] = dp[j - 1][i - 1][0] + dp[j - 1][i - 1][1] * a[j]; 
                dp[j][i][1] = dp[j - 1][i - 1][1];
                dp[j][i][0] += dp[j + 1][i - 1][0] + dp[j + 1][i - 1][1] * a[j]; 
                dp[j][i][1] += dp[j + 1][i - 1][1];
            }
            dp[j][i][0] %= mod;
            dp[j][i][1] %= mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][k][0];
        ans %= mod;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            sum[i] += dp[i][j][1] * dp[i][k - j][1];
            sum[i] %= mod;
        }
    }
  //  cout << sum[1] << endl;

    while (q--) {
        ll x, y; scanf("%lld %lld", &x, &y);
        if (y >= a[x]) {
            ll cnt = y - a[x];
            ll cat = (cnt % mod * sum[x] % mod) % mod;
            ans = ans + cat;
            ans = ans % mod;
        } else {
            ll cnt = a[x] - y;
            ll cat = (cnt % mod * sum[x] % mod) % mod;
            ans = (ans - cat + mod) % mod;
        }
        a[x] = y;
        printf("%lld\n", ans);
    }

}

