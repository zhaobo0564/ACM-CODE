#include<bits/stdc++.h>
using namespace std;

const int N = 507;

int n, a[N][N], dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -10000000;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int ans = -10000000;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;

}