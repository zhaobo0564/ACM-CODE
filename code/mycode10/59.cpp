#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

int mp[N][N], n, m, k;

typedef long long ll;

const ll mod = 998244353;

bool judge(int x, int y) {
    if (x < 0 || y < 0 || x > n || y > m) {
        return false;
    }
    return true;
}

ll inv, fn[N * N], dp[N][N];

ll dfs(int x, int y) {
    if (x == n && y == m) {
         return fn[n * m - k];
    }
    if (dp[x][y] != -1) return dp[x][y];
    ll ans = 0;
    if (judge(x + 1, y) && judge(x, y + 1)) {
        if (mp[x][y] == 1) {
            ans += dfs(x, y + 1);
        } else if (mp[x][y] == 2){
            ans += dfs(x + 1, y);
        } else if (mp[x][y] == 3) {
            ans += dfs(x + 1, y);
            ans = ans % mod;
            ans += dfs(x, y + 1);
        } else {
            ans += (dfs(x + 1, y) % mod * inv % mod) % mod;
            ans = ans % mod;
            ans += (dfs(x, y + 1) % mod* inv % mod) % mod;
            ans = ans % mod;
            ans += (dfs(x + 1, y)%mod * inv % mod) % mod;
            ans = ans % mod;
            ans +=( dfs(x, y + 1) % mod* inv % mod) % mod;
        }
    } else if (judge(x + 1, y)) {
        if (mp[x][y] == 2){
            ans += dfs(x + 1, y);
        } else if (mp[x][y] == 3) {
            ans += dfs(x + 1, y);
        } else if (mp[x][y] == 0) {
            ans += (dfs(x + 1, y) % mod * inv % mod) % mod;
            ans = ans % mod;
            ans += (dfs(x + 1, y) % mod* inv % mod)% mod;
        }
    } else if (judge(x, y + 1)) {
        if (mp[x][y] == 1) {
            ans += dfs(x, y + 1);
        } else if (mp[x][y] == 3) {
            ans += dfs(x, y + 1);
        } else if (mp[x][y] == 0) {
            ans +=( dfs(x, y + 1) % mod* inv %mod) % mod;
            ans += (dfs(x, y + 1)% mod * inv % mod) % mod;
        }
    }
    ans = ans % mod;

    return dp[x][y] = ans;

    
}

ll ksm(ll x, ll y) {
    x = x % mod;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

int main() {
    ios::sync_with_stdio(0);
    fn[0] = 1;
    for (int i = 1; i < N * N; i++) {
        fn[i] = fn[i - 1] * 3 % mod;
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {

        int x, y;
        char c; cin >> x >> y >> c;
        if (c == 'R') {
            mp[x][y] = 1;
        } else if (c == 'D') {
            mp[x][y] = 2;
        } else {
            mp[x][y] = 3;
        }
    }
    inv = ksm(3, mod - 2);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1) << endl;
    

}