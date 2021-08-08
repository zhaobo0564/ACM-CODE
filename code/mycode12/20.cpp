#include<bits/stdc++.h>
using namespace std;

const int N = 100007;
int a[N], n, dp[N], maxn[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, 0, sizeof(dp));
    memset(maxn, 0, sizeof(maxn));
    for (int i = 1; i <= n; i++) {
     //   cout << "A " << a[i] << endl;
        for (int j = 1; j * j <= a[i]; j++) {
        
            if (a[i] % j == 0) {
                if (j != 1)
                    dp[i] = max(dp[i], maxn[j] + 1);
                dp[i] = max(dp[i], maxn[a[i] / j] + 1);
            }
        }


        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                maxn[j] = max(maxn[j], dp[i]);
                maxn[a[i] / j] = max(maxn[a[i] / j], dp[i]);
            }
        }
        // for (int j = 1; j < i; j++) {
        //     if (__gcd(a[i], a[j]) > 1) {
        //         dp[i] = max(dp[i], dp[j] + 1);
        //     }
        // }
    }
    for (int i = 1; i <= n; i++) {
        dp[0] = max(dp[0], dp[i]);
    }
    cout << dp[0] << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}