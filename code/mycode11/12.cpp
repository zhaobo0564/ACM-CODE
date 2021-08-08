#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a[N], k, l[N];

int sum[N];

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            sum[i] %= k;
        }
        for (int i = 0; i <= k; i++) {
            l[i] = n + 10;
        }
        int ans = -1;
        l[0] = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, i - l[sum[i]]);
            l[sum[i]] = min(i, l[sum[i]]);
        }
        cout << ans << endl;

    }
}