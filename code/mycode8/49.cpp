#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], n, x, dp[N];

int dfs(int p) {
    if (p > n) return 0;
    if (dp[p] != -1) return dp[p];
    int cnt = x / a[p];
    if (x % a[p]) cnt++;
    int ans = 0;
    if (p + cnt - 1 <= n)
        ans = max(ans, dfs(p + cnt ) + 1);
    ans = max(ans, dfs(p + 1));
    return dp[p] = ans;
}

int main() {
    //ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {

    
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            dp[i] = -1;
        }
        dp[0] = dp[n + 1] = -1;
        sort(a + 1, a + n + 1);
        cout << dfs(1) << endl;
    }
}