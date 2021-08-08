#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
typedef long long ll;

ll n, k, q, a[N];

pair<ll, ll> dp[N][N];
const ll mod = 1e9 + 7;

pair<ll, ll> dfs(int p, int sum) {
    //cout << "p = " << p <<  " sum = " << sum << endl;
    if (sum == 0) {
        return {1, a[p]};
    }
    if (dp[p][sum].first != -1) return dp[p][sum];
    ll ans = 0;
    ll cnt = 0;
    if (p > 1) {
        auto cd =  dfs(p - 1, sum - 1);
        ans +=cd.second + cd.first * a[p];
        cnt += cd.first;
    } 
    if (p < n) {
        auto cd  = dfs(p + 1, sum - 1);
        ans +=cd.second + cd.first * a[p];
        cnt += cd.first;

    }
    return dp[p][sum] = {cnt % mod, ans % mod};
} 

int main() {
    cin >> n >> k >> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j].first = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dfs(i, k).second;
        ans %= mod;
      //  cout << ans << endl;
    }

    cout << ans << endl;

    
}

