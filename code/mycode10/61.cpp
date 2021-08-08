#include<bits/stdc++.h>

using namespace std;

const int N = 12;

int mp[N][N], n, dp[N][1 << N];

int dfs(int stat, int cnt) {
    if (cnt == n) {
        return 0;
    }
    if (dp[cnt][stat] != -1) return dp[cnt][stat];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((stat & (1 << i))) continue;
        for (int j = 0; j < n; j++) {
            if ((stat & (1 << j))) {

            } else {
                ans = max(ans, dfs(stat + (1 << j), cnt + 1) + mp[i][j]);
            }
        }
    }
    return dp[cnt][stat] = ans;
}

int main() {
    while (cin >> n && n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mp[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(0, 1);
        cout << ans << endl;
    }

}