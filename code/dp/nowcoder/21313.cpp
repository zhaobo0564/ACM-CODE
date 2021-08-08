#include<bits/stdc++.h>
using namespace std;

const int N = 51;
typedef long long ll;

const ll mod = 1e9 + 7;
ll n, a[N], dp[N][N * N][N][2];

ll dfs(int p, int sum, int last, int ok) {
    if (p > n) return 1;
    if (dp[p][sum][last][ok] != -1) return dp[p][sum][last][ok];
    ll ans = 0;
    if (a[p] == -1) {
        for (int i = 0; i <= 40; i++) {
            if ( i * (p - 1) > sum) break;
            if (ok == 1) {
                if (i < last) {

                } else {
                    ans = ans + dfs(p + 1, sum + i, i, 0);
                }
            } else {
                if (i < last) {
                    ans = ans + dfs(p + 1, sum + i, i, 1);
                } else {
                    ans = ans + dfs(p + 1, sum + i, i, 0);
                }
            }
           
        }
    } else {
        int cnt = a[p] * (p - 1);
        if (cnt <= sum) {
            if (ok == 1) {
                if (a[p] < last) {

                } else {
                    ans = ans + dfs(p + 1, sum + a[p], a[p], 0);
                }
            } else {
                if (a[p] < last) {
                    ans = ans + dfs(p + 1, sum + a[p], a[p], 1);
                } else {
                    ans = ans + dfs(p + 1, sum + a[p], a[p], 0);
                }
            }
        }
    }
    ans = ans % mod;
    dp[p][sum][last][ok] = ans;
    return ans;
    
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, 0, 0, 0);
    cout << ans << endl;
}