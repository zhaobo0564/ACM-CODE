
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
const ll mod = 1004535809;
vector<int> g[N];
ll n, m, a[N];
ll dp[N][2], sum[N];

void dfs(int u) {
    for (int to : g[u]) {
        
    }
}



int main() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        g[x].push_back(i);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        res ^= a[i];
    }
    if (res != 0 && res != m) {
        puts("0");
    } else {
        ll ans = 0;
        dfs(1);
        ans = (dp[1][1] + dp[1][0]) % mod;
        cout << ans << endl;
    }
}