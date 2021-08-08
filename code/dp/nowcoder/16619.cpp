#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;

ll dp[100][100];

ll dfs(int p, int sum) {
    ll ans = 0;
    if (sum == 0) {
        if (p == 1) {
            return 1;
        }
        return 0;
    }
    if (dp[p][sum] != -1) return dp[p][sum];

    if (p == 1) {
        ans = ans + dfs(n, sum - 1);
        ans = ans + dfs(p + 1, sum - 1);
    } else if (p == n) {
        ans = ans + dfs(p - 1, sum - 1);
        ans = ans + dfs(1, sum - 1);
    } else {
        ans = ans + dfs(p + 1, sum - 1);
        ans = ans + dfs(p - 1, sum - 1);
    }
    return dp[p][sum] = ans;
}


int main() {
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, m);
    printf("%lld\n", ans);
    
}