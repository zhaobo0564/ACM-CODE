#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int n, a[N], m;

int dp[106][10007][106];

int dfs(int p, int sum, int day) {
    if (p > n) {
        if (sum >= m) return 0;
        return -1e5;
    }
    int ans = -1e5;
    ans = max(ans, dfs(p + 1, sum + a[p], 1) + 1);
    ans = max(ans, dfs(p + 1, sum + max(0, a[p] - day), day + 1));
    ans = max(ans, dfs(p + 1, sum, day));
    return ans;
    
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));


    cout << dfs(1, 1, 0) << endl;




}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;

    while (t--) {
        solve();
    }
}