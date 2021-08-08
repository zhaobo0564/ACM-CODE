#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, b;
ll money[20][20], people[20][20], vis[20][20];;

ll dp[20][200000];
int top = 1;

ll dfs(int x, int b) {
   // cout << "b = " << b << endl;
    if (x > n ) {
       
        return 0;
    }
    if (dp[x][b] != -1) return dp[x][b];
    ll ans = 0;
    for (int i = 1; i <= 4; i++) {
        if (b >= money[x][i]) {
            
            ans = max(ans, dfs(x + 1, b - money[x][i]) + people[x][i]);
        }
    }
    ans = max(ans, dfs(x + 1, b));
    return dp[x][b] = ans;
}


void solve() {
    scanf("%d %d", &n, &b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> money[i][j] >> people[i][j]; 
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("Budget #%d: Maximum of %lld lives saved.\n\n", top++, dfs(1, b));
  //  cout << dfs(1, b) << endl;
}

int main() {
   // ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}