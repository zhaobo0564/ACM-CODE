#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
char s[200];
int n;
int dp[200][2][200];

int dfs(int p, int last, int pos) {
    if (p > n) {
        return 1;
    }
   if (dp[p][last][pos] != -1) return dp[p][last][pos];
    int ans = 0;
    int cnt = s[p] - '0';
    if (p > pos + 1) {
        ans = max(ans, dfs(p + 1, last, p));
    }
    if (cnt >= last) {
        ans = max(ans, dfs(p + 1, cnt, pos));
    } 
    return  dp[p][last][pos] = ans;
}

void solve() {
    
    cin >> (s + 2);
    n = strlen(s + 2) + 1;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            dp[i][0][j] = dp[i][1][j] = -1;
        }
    }
    if (dfs(2, 0, 0) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}