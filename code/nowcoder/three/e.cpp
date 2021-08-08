#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
int t, n;
ll a[N], dp[N][2];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            dp[i][0] = dp[i][1] = 1e12;
        }

        sort(a + 1, a + n + 1);
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            if (i + 3 <= n) {
                dp[i + 3][0] = min(dp[i - 1][1] + a[i + 3] - a[i], dp[i - 1][0] + a[i + 3] - a[i]);
            }
            if (i + 5 <= n) {
            
                dp[i +5][1] = min(dp[i- 1][0] + (a[i + 5] - a[i]), dp[i -1][1] + a[i + 5] - a[i]);
            }
        }
        printf("%lld\n", min(dp[n][0], dp[n][1]) * 2);
        

    }
}