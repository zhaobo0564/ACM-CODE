#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 507;
const ll mod = 1e9 + 7;
int up[N], X, Y, n;
string s;
ll dp[N][130000][2];



ll dfs(int p, int x, int y, int limit) {
    if (p >= n) {
        if (x == X && y == Y) return 1;
        return 0;
    }
    ll ans = 0;
    int maxn = 9;
    if (limit) maxn = up[p];
    for (int i = 0; i <= maxn; i++) {
        if (i == 8) {
            ans += dfs(p + 1, x + 1, y, limit & i == maxn);
        } else if (i == 6) {
            ans += dfs(p + 1, x, y + 1, limit & i == maxn);
        } else {
            ans += dfs(p + 1, x, y, limit & i == maxn);
        }
        ans %= mod;
    }
    return ans;
}

int main() {
    cin >> s >> X >> Y;
    n = s.length();
    for (int i = 0; i < s.length(); i++) {
        up[i] = s[i] - '0';
    }

}