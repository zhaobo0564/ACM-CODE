#include<bits/stdc++.h>
using namespace std;
const int N = 500;

int a[N], t, n;

int dp[N][N];
int cnt = 0;

int dfs(int p, int time) {
   
    if (p > n) {
        return 0;
    }
    if (dp[p][time] != -1) return dp[p][time];
     cnt++;
    int ans = 1e8;
    for (int i = time; i <= 400; i++) {
        ans = min(ans, dfs(p + 1, i + 1) + abs(a[p] - i));
    }
    return dp[p][time] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            //cin >> a[i];
            a[i] = i;
        }
        sort(a + 1, a + n + 1);
        memset(dp, -1, sizeof(dp));
        cout << dfs(1, 1) << endl;
        cout << cnt << endl;
    }
}