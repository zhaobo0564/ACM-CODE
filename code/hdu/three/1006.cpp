#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int up[20], t, n, vis[10];
string s;

ll dp[20][20][2];

ll dfs(int p, int d, int num, int f, int sum) {
 
 
    if (p == n) {
        if (sum == num) return 1;
        return 0;
    } 
    if (dp[p][sum][f] != -1) return dp[p][sum][f];
    int maxn;
    if (f) {
        maxn = up[p];
    } else {
        maxn = 9;
    }
    ll ans = 0;
    for (int i = 0; i <= maxn; i++) {
        if (vis[i] >= num) {
            continue;
        }
        if (i != d && vis[i] + 1 == num) {
            continue;
        }
        if (i == d) {
            vis[i]++;
            ans += dfs(p + 1, d, num , f && i == maxn, sum + 1);
            vis[i]--;
        } else {
            vis[i]++;
            ans += dfs(p + 1, d, num, f && i == maxn, sum);
            vis[i]--;
        }
    }
    dp[p][sum][f] = ans;
    return ans;
      
}




ll work(ll a, int d) {
        
        int cnt = 0;
        while (a) {
          up[cnt] = a % 10;
          cnt++;
          a = a / 10;
        }
        n = cnt;
        reverse(up, up + cnt);

        ll ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int maxn;
            if (i == 0) {
                maxn = up[i];
            } else {
                maxn = 9;
            }
            memset(dp, -1, sizeof(dp));
           // memset(vis, 0, sizeof(vis));
            for (int j = 1; j <= maxn; j++) {
                for (int k = 1; k <= 18; k++) {
                    memset(dp, -1, sizeof(dp));

                   if (vis[i] >= k) {
                        continue;
                    }
                    if (i != d && vis[i] + 1 == k) {
                        continue;
                    }
                    if (i == d) {
                        vis[i]++;
                        ans += dfs(i + 1, d, k , i == 0 && j == maxn,  1);
                        vis[i]--;
                    } else {
                        vis[i]++;
                        ans += dfs(i + 1, d, k, i == 0 && j == maxn, 0);
                        vis[i]--;
                    }
                }
            }
        }
        return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        int d; cin >> d;
        ll ans = work(r, d);
        ans = ans - work(l - 1, d);
        printf("%lld\n", ans);
       


        

    }
}