#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

typedef long long ll;

ll vis[N], n, a[N], dp[N];

ll dfs(int p) {
    if (p > n) return 0;
    if (dp[p] != -1) return dp[p];
    ll ans = 0;

    ll pos1 = upper_bound(a + 1, a + n + 1, a[p]) - a;
    ll pos = upper_bound(a + 1, a + n + 1, a[p] + 1) - a;
    ans = max(ans, dfs(pos) + (pos1 - p) * a[p]);
    ans = max(ans, dfs(p + 1));
   

    return dp[p] = ans;
   

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1) << endl;

}