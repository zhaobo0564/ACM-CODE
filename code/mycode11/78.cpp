#include<bits/stdc++.h>
using namespace std;

const int N = 1007;
typedef long long ll;
const ll mod = 1e9 + 7;

int n;

int a[] = {0, 1, 2, 3};

ll dp[N][2][2][2][2];

ll dfs(int p, int zero, int one, int two, int three) {
    if (p > n) {
        if (zero && one && two && three) {
            return 1;
        }
        return 0;
    }
    if (dp[p][zero][one][two][three] != -1) return dp[p][zero][one][two][three];
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        if (one) {
            if (i == 0) continue;
            if (three) {
                if (i == 2) continue;
                ans += dfs(p + 1, zero, one, two, three);
            } else {
                if (i == 1) {
                    ans += dfs(p + 1, zero, one, two, three);
                } else if (i == 2) {
                    ans += dfs(p + 1, zero, one, 1, three);
                } else if (i == 3) {
                    ans += dfs(p + 1, zero, one, two, 1);
                }
            }

        } else {
             if (three) {
                if (i == 2) continue;
                if (i == 0) {
                    ans += dfs(p + 1, 1, one, two, three);
                } else if (i == 1) {
                    ans += dfs(p + 1, zero, 1, two, three);
                } else {
                    ans += dfs(p + 1, zero, one, two, three);
                }
                
            } else {
                if (i == 0) {
                    ans += dfs(p + 1, 1, one, two, three);
                } else if (i == 1) {
                    ans += dfs(p + 1, zero, 1, two, three);
                } else if (i == 2) {
                    ans += dfs(p + 1, zero, one, 1, three);
                } else if (i == 3) {
                    ans += dfs(p + 1, zero, one, two, 1);
                }
            }
        }
        ans = ans % mod;
    }
    return dp[p][zero][one][two][three] = ans;
    
}

int main() {
    cin >> n;
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    ans += dfs(2, 0, 1, 0, 0);
    ans += dfs(2, 0, 0, 1, 0);
    ans += dfs(2, 0, 0, 0, 1);
    cout << ans << endl;

}