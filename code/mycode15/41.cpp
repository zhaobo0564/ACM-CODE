#include<bits/stdc++.h>
using namespace std;
const int N = 1007;
typedef long long ll;
const ll mod = 998244353;

char s[N], t[N];
int k, vis[20];
vector<int> ans;
ll dp[N][N][2];

ll dfs(int p, int limit, int sum) {
    if (p >= ans.size()) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }
    if (dp[p][sum][limit] != -1) return dp[p][sum][limit];
    ll an = 0;
    int maxn = ans[p];
    if (!limit) maxn = 9;
    for (int i = 0; i <= maxn; i++) {
        if (vis[i]) {
            an += dfs(p + 1, limit & i == maxn, sum + 1);
            an %= mod;
        } else {
            an += dfs(p + 1, limit & i == maxn, sum);
            an %= mod;
        }
    }
    return  dp[p][sum][limit] = an;
}

ll work(char *p) {
    int n = strlen(p);
    ans.clear();
    for (int i = 0; i < n; i++) {
        ans.push_back(p[i] - '0');
    }
    memset(dp, -1, sizeof(dp));
    return dfs(0, 1, 0);

}

int main() {
    cin >> s >> t >> k;
    vis[2] = vis[3] = vis[5] = vis[7] = 1;
    ll r = work(t);
    ll l = work(s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[s[i] - '0']) {
            cnt++;
        }
    }
    if (cnt == k) {
        l = (l - 1 + mod) % mod;
    }
    cout << (r - l + mod) % mod << endl;
    return 0;


}