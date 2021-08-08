#include<bits/stdc++.h>
using namespace std;
int n;

int dp[10000][1000][2];

char s[1000000];
int dfs(int p, int k, int f) {
    if (p > n) return 0;
    if (dp[p][k][f] != -1) return dp[p][k][f];
    int ans = 0;
    if (f == 1) {
        if (k) {
           if (s[p] == 'W') {
               ans = max(ans, dfs(p + 1, k, f) + 2);
           } else {
               ans = max(ans, dfs(p + 1, k - 1, f) + 2);
               ans = max(ans, dfs(p + 1, k, 0));
           }
        } else{
            if (s[p] == 'W') {
                ans = max(ans, dfs(p + 1, k, f) + 2);
            } else
                ans = max(ans, dfs(p + 1, k, 0));
        }
    } else {
         if (k) {
           if (s[p] == 'W') {
               ans = max(ans, dfs(p + 1, k, 1) + 1);
           } else {
               ans = max(ans, dfs(p + 1, k - 1, 1) + 1);
               ans = max(ans, dfs(p + 1, k, 0));
           }
        } else{
            if (s[p] == 'W') {
                ans = max(ans, dfs(p + 1, k, 1) + 1);
            } else
                ans = max(ans, dfs(p + 1, k, 0));
        }

    }
    return dp[p][k][f] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int k; cin >> n >> k;
    cin >> s + 1;
    cout << dfs(1, k, 0) << endl;

}