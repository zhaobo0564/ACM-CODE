#include<bits/stdc++.h>
using namespace std;
const int N = 10000;


#define int unsigned int

int n, m, q;


int a[N], b[N];

int ans = 0;

long long dp[1007][267];

long long dfs(int p, int v, int end) {
    if (p > end) {
        if (v == 0) return 0;
        return -1e5;        
    }
    if (dp[p][v] != -1) return dp[p][v];
    long long ans = -1e5;
    ans = max(ans, dfs(p + 1, v ^ a[p], end) + b[p]);
    ans = max(ans, dfs(p + 1, v, end));

    return dp[p][v] = ans;

}

void work(int l, int r, int x) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
        dfs(l, i, r);

    for (int i = 0; i < m; i++) {
        if (dp[l][i] < 0) {
            cout << -1 << endl;
            ans += (-1 * (x ^ i));
        } else {
            cout << dp[l][i] << endl;
            ans += (dp[l][i] * (x ^ i));
        }
    }
   
    
    
}

vector<int> g;

int32_t main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int k = 1;
    int sum = 0;
    while (q--) {
        ans = 0;
        int l, r;
        int x;
        cin >> l >> r >> x;
        l++, r++;
        work(l, r, x);
        sum += ans ^ k;
        k++;
        cout << ans << endl;
        
    }
    //cout << ans << endl;
    cout << sum << endl;
}
