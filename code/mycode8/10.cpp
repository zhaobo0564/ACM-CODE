#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

char s[N];

int a, b, nxt[N][2], n;
ll dp[N][2];

ll dfs(int p, int f) {
    if (p > n) {
        if (f == 0)
            return 0;
        return 1e9;
    }
    if (dp[p][f] != -1)return dp[p][f];
    ll ans = 1e9; 
    
    if (f) {
        if (s[p] == '1') {
            ans = min(ans, dfs(p + 1, 0) + a);
            ans = min(ans, dfs(p + 1, f));
        } else {
            ans = min(ans, dfs(p + 1, f) + b);
        }
    } else {
        if (s[p] == '1') {
            ans = min(ans, dfs(p + 1, 0) + a);
            ans = min(ans, dfs(p + 1, 1));
        } else {
            ans = min(ans, dfs(p + 1, f));
        }
    }

    return dp[p][f] = ans;
}

void solve() {
    cin >> a >> b;
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 0; i <= n + 1; i++) {
        dp[i][0] = dp[i][1] = -1;
    }

    cout << dfs(1, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}