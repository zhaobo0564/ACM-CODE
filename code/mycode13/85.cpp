#include<bits/stdc++.h>
using namespace std;
string s;
int n;
const int mod= 100019;
int dp[1000007][11];
int dfs(int p, int last) {
    if (p > n) return 1;
    int ans = 0;
    if (dp[p][last] != -1) return dp[p][last];
    for (int i = last; i <= 9; i++) {
        ans += dfs(p + 1, i);
        ans %= mod;
    }
    return dp[p][last] = ans;
}



int main() {
   cin >> n;
   int ans = 0;
   memset(dp, -1, sizeof(dp));
   for (int i = 1; i <= 9; i++) {
       ans += dfs(2, i);
       ans = ans % mod;
   }
   cout << ans << endl;
}