#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;
#define int long long

int mp[1000][1000];

int dp[N], maxn[N];




struct node {
    int t, x, y;
} p[N];

int r, n;

void solve() {
    cin >> r >> n;
    for (int i = 2; i <= n + 1; i++) {
        cin >> p[i].t >> p[i].x >> p[i].y;
    }
    p[1].t = 0;
    p[1].x = 1;
    p[1].y = 1;
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = -1e17;
    }

    dp[1] = 0;
    for (int i = 2; i <= n + 1; i++) {
        
        for (int j = i - 1; j ; j--) {
            if (p[i].t - p[j].t >= 1000) {
                dp[i] = max(dp[i], maxn[j] + 1);
                break;
            } else if (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= p[i].t - p[j].t) {
                dp[i] = max(dp[i], dp[j] + 1);
            } 
        }
        ans = max(dp[i], ans);
        maxn[i] = max(maxn[i - 1], dp[i]);
    }
    cout << ans << endl;
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}