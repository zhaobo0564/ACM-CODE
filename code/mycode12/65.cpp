#include<bits/stdc++.h>

using namespace std;

const int N = 5007;

typedef long long ll;

ll n, m, dp[N][N][2];
const ll mod = 998244353;

pair<ll, ll> dfs(int p, int last, int f) {
    if (p > n) return {0, 1};
    ll ans = 0, cnt = 0;
    pair<ll, ll> x = dfs(p + 1, last, 0);
    ll cn = x.second;
    cnt += cn;
    ans += x.first;
    pair<ll, ll> y = dfs(p + 1, last, 1);
    cn = y.second;
    cnt += cn;
    ans += x.first;

    if (last + 1 <= m && f) {
        x = dfs(p, last + 1, f);
        cn = x.second;
        ans += x.first;
        cnt += cn;
        cnt %= mod;
        ans = ans % mod;
        x = dfs(p + 1, last + 1, f);
        cn = x.second;
        ans += x.first + cn;
        cnt += cn;
        cnt %= mod;
        ans = ans % mod;
        x = dfs(p + 1, last + 1, f ^ 1);
        cn = x.second;
        ans += x.first + cn;
        cnt += cn;
        cnt %= mod;
        ans = ans % mod;
    }
    if (last - 1 > 0 && !f) {
        x = dfs(p, last - 1, f);
        cn = x.second;
        ans += x.first;
        cnt += cn;
        cnt %= mod;
        ans = ans % mod;
        x = dfs(p + 1, last - 1, f);
        cn = x.second;
        ans += x.first;
        cnt += cn;
        cnt %= mod;
        ans = ans % mod;
    }
    return {ans, cnt};
    
} 

int main() {
    cin >> n >> m;
    ll ans = dfs(1, 1, 1).first;

    cout << ans << endl;
    
}