#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 107;
ll n, a[N];



ll dp[N][N];

ll dfs(int l, int r) {
    if (r - l <= 1) {
      //  cout << "YES\n";
        
        return 0;
    }
    if (dp[l][r] != -1) return dp[l][r];
    
    ll ans = 1e10;
    for (int i = l + 1; i < r; i++) {
        ans = min(ans, dfs(i, r) + (r - l - 2) * a[i] + dfs(l, i));
    }

    return dp[l][r] = ans;

    
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);

        }
        memset(dp, -1, sizeof(dp));
        cout << dfs(0, n + 1) << endl;
    }
}