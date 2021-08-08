#include<bits/stdc++.h>
using namespace std;
const int N = 10007;

int dp[1007][N];

int dfs(int s, int t) {
    if (s == 0 && t == 0) return 0;
    if (s < 0 || t < 0) return 1000000;
    if (dp[s][t] != -1) return dp[s][t]; 
    int ans = 1e8;
    for (int i = 1; i <= 9; i++) {
        if (s - i >= 0 && t - i * i >= 0)
            ans = min(ans, dfs(s - i, t -  i * i) + 1);
    }
    return dp[s][t] = ans;
}

void solve() {
    int s, t; cin >> s >> t;
  //  cout << dfs(s, t) << endl;
    if (s  > 900 || t > 900 * 9 || dfs(s, t) > 100 ) {
        puts("No solution");
    } else {
        vector<int> ans;
        while (1) {
            for (int i = 1; i <= 9; i++) {
                if (dfs(s, t) - 1 == dfs(s - i, t - i * i)) {
                    ans.push_back(i);
                    s = s - i;
                    t = t - i * i;
                    break;
                }
            }
            if (s == 0 && t == 0) {
                break;
            }
        }
        for (int i: ans) {
            cout << i;
        }
        cout << endl;
    }

}

int main() {
    memset(dp, -1, sizeof(dp));
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}