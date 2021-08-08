#include<bits/stdc++.h>

using namespace std;
const int N = 1007;
int w[N], t[N], T, n;
int dp[107][N];

set<pair<int,int> >sa;

int dfs(int p, int v) {
    
    if (p > n) {
        return 0;
    }
    if (dp[p][v] != -1){
        //cout << "BBB\n";
        return dp[p][v];
    }
    int ans = 0;
    if (v >= t[p]) {
        ans = max(ans, dfs(p + 1, v - t[p]) + w[p]);
    }
    ans = max(ans, dfs(p + 1, v));
    return dp[p][v] = ans;
}

int main() {
    cin >> T >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> w[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(1, T);
    cout << ans << "\n";
}