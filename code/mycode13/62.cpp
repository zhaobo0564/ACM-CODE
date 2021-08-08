#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int dp[N], n, m, fn[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        for (int j = 0; j <= m; j++) {
            fn[j] = 2e6;
        }
        for (int j = 0; j <= m; j++) {
            ll cnt = 0;
            if (t == 1) {
                cnt = (1ll*j * 100000 + x + 99999) / 100000;
            } else {
                cnt = (1ll*j * x + 99999) / 100000;
            }
            if (cnt > m) break;
            if (dp[j] != -1) {
                fn[j] = 0;
            }
        //    cout << "cnt = " << cnt << endl;
            fn[cnt] = min(fn[cnt], fn[j] + 1);

        }
        for (int j = 0; j <= m; j++) {
            if (dp[j] == -1 && fn[j] <= y) {
                dp[j] = i;
            }
        }

    }
    for (int j = 1; j <= m; j++) {
        cout << dp[j] << " ";
    }
    cout << endl;
}