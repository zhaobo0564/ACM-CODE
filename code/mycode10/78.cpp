#include<bits/stdc++.h>

using namespace std;

string s[100];

int n;

typedef long long ll;
ll dp[100][3];

ll dfs(int p, int f) {

    if (p > n) {
        return f;
    }
    if (dp[p][f] != -1) return dp[p][f];
    ll ans = 0;
    if (s[p] == "AND") {
        ans += dfs(p + 1, f & 1);
        ans += dfs(p + 1, f & 0);
    } else {
        ans += dfs(p + 1, f | 1);
        ans += dfs(p + 1, f | 0);
    }
    return dp[p][f] = ans;

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, 0);
    ans += dfs(1, 1);

    cout << ans << endl;
}