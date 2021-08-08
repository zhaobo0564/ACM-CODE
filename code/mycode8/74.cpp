#include<bits/stdc++.h>
using namespace std;
const int N = 5007;

char s[N], t[N];
 int n, m; 
 int dp[N][N][2];
int dfs(int i, int j, int f) {

    if (i > n || j > m) return 0;
    if (dp[i][j][f] != -1) return dp[i][j][f];
    int ans = 0;
    if (s[i] == t[j]) {
        ans = max(ans, dfs(i + 1, j + 1, 1) + 2);
        if (f) {
            ans = max(ans, dfs(i + 1, j, f) - 1);
            ans = max(ans, dfs(i, j + 1, f) - 1);
        } else {
            ans = max(ans, dfs(i + 1, j, f));
            ans = max(ans, dfs(i, j + 1, f));
        }
    } else {
        if (f) {
            ans = max(ans, dfs(i + 1, j, f) - 1);
            ans = max(ans, dfs(i, j + 1, f) - 1);
        } else {
            ans = max(ans, dfs(i + 1, j, f));
            ans = max(ans, dfs(i, j + 1, f));
        }
    }

    return dp[i][j][f] = ans;
    

}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> (s + 1) >> (t + 1);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1, 0) << endl;
}