#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll;
const ll mod = 998244353;
string s[N];
ll fn[N];
int n, m, cnt;
ll dp[N][2];

vector<char> g; 

int sum[N];
void init() {
    int cnt = 0;
    sum[g.size()] = 0;
    for (int i = g.size() - 1; i >= 0; i--) {
        dp[i][0] = dp[i][1] = -1;
        if (g[i] == 'o') cnt++;
        sum[i] = cnt;
    }
}



ll dfs(int p, int f) {
    if (p >= g.size()) {
        return 0;
    }
    if (dp[p][f] != -1) return dp[p][f];
    ll ans = 0;
    if (f) {
        if (g[p] == 'o') {
            ans += dfs(p + 1, 0) + fn[sum[p + 1]];
            ans %= mod;
            ans += dfs(p + 1, 0);
            ans %= mod;
        } else {
            ans += dfs(p + 1, 0);
            ans %= mod;
        }
    } else {
        if (g[p] == 'o') {
            ans += dfs(p + 1, 1);
            ans %= mod;
            ans += dfs(p + 1, 0);
            ans %= mod;
        } else {
            ans += dfs(p + 1, 0);
            ans %= mod;
        }
    }
    return dp[p][f] = ans;
}


int main() {
    ios::sync_with_stdio(0);
    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == 'o') {
                cnt++;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        g.clear();
        for (int j = 0; j < s[i].length(); j++) {
            g.push_back(s[i][j]);
        }
        init();
        ans += (dfs(0, 0) % mod * fn[cnt - sum[0]] % mod) % mod;
        ans %= mod;
    }

    for (int i = 0; i < m; i++) {
        g.clear();
        for (int j = 1; j <= n; j++) {
            g.push_back(s[j][i]);
        }
        init();
        ans += (dfs(0, 0) % mod * fn[cnt - sum[0]] % mod) % mod;
        ans %= mod;
    }
    cout << ans  << endl;
    
    return 0;
}