#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int a[N];
int n;
int vis[N];
int dp[N][2];

int dfs(int p, int ok) {
    if (p == 0) return 0;
    if (dp[p][ok] != -1) return dp[p][ok];
    int ans = 0;
    if (p - a[p] >= 0) {
        ans = max(ans, dfs(p - a[p], 1) + 1);
    }
    if (ok)
        ans = max(ans, dfs(p - 1, ok));
    return dp[p][ok] = ans;
}

int main() {
   cin >> n;
   int maxn = 0;
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
       maxn = max(maxn, a[i]);
   }
   if (maxn > n) {
       puts("-1");
   } else {
        sort(a + 1, a + n + 1);
        memset(dp, -1, sizeof(dp));
        int ans = dfs(n, 0);
        printf("%d\n", ans);
   }

   
}