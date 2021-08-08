#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll n, a[N];
int vis[N];

vector<int> g[N];

void init() {
    int ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if (i == j) continue;
            g[i].push_back(j);
            ans++;
        }
    }
}

int dp[N];

int dfs(int u) {
    int ans = 0;
   // cout << "u " << u << endl;
    if (dp[u] != -1) return dp[u];
    for (int to: g[u]) {
        if (vis[to]) {
            ans =max(ans, dfs(to) + vis[to]);
        }
    }
    return dp[u] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
        dp[a[i]] = -1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(a[i]) + vis[a[i]]);
    }

    cout << n - ans << endl;

    for (int i = 1; i <= n; i++) {
        vis[a[i]] = 0;
    }

  




}

int main() { 
    init();
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}