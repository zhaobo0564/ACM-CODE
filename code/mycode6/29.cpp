#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

int n, a[N], dp[N][3];

int dfs(int p, int ok) {
    if (p > n) return 0;
    if (dp[p][ok] != -1) return dp[p][ok];
    int ans = 1e8;
    if (ok == 0) {
        if (a[p] == 1) {
            if (p < n) {
                if (a[p + 1] == 1) {
                    ans = min(ans, dfs(p + 1, 1) + 1);
                    ans = min(ans, dfs(p + 2, 1) + 2);
                } else {
                    ans = min(ans, dfs(p + 2, 1) + 1);
                    ans = min(ans, dfs(p + 1, 1) + 1);
                }
            } else {
                ans = min(ans, dfs(p + 1, 1) + 1);
            }
        } else {
           if (p < n) {
               if (a[p + 1] == 0) {
                   ans = min(ans, dfs(p + 2, 1));
                   ans = min(ans, dfs(p + 1, 1));
               } else {
                   ans = min(ans, dfs(p + 2, 1) + 1);
                   ans = min(ans, dfs(p + 1, 1));
               }
           } else {
               ans = min(ans, dfs(p + 1, 1));
           }
        }
    } else {
        if (p < n) {
            ans = min(ans, dfs(p + 2, 0));
            ans = min(ans, dfs(p + 1, 0));
        } else {
            ans = min(ans, dfs(p + 1, 0));
        }
    }
    return dp[p][ok] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = -1;
    }
    //memset(dp, -1, sizeof(dp));
    
    cout << dfs(1, 0) << endl;

}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}