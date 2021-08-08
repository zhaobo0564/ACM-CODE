#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], n;
vector<int> g[N];
typedef long long ll;

ll dp[N], sz[N], sum[N];

void dfs(int u, int fa) {
    if (fa && g[u].size() == 1) {
        dp[u] = a[u];
        sz[u] = 1;
        sum[u] = a[u];
        return;
    }
  
    for (int to: g[u]) {
        if (fa == to) continue;
        dfs(to, u);
        dp[u] = max(dp[to], dp[u]);
        sz[u] += sz[to];
        sum[u] += sum[to];
    }
    ll cnt = sz[u] * dp[u];
    if (cnt - sum[u] >= a[u]) {
        sum[u] = sum[u] + a[u];
    } else {
        ll cat = a[u] - (cnt - sum[u]);
       // cout << "cat " << cat << endl;
        ll ca = cat / sz[u];
        ll mod = cat % sz[u];
        sum[u] = sum[u] + a[u];
     //   cout << "dp " << dp[u] << "u " << u << endl;
        dp[u] = dp[u] + ca + mod > 0? 1: 0;
    }
    
}


int main() {
    cin >> n;
   
    for (int i = 2; i <= n; i++) {
        int u; scanf("%d", &u);
        g[i].push_back(u);
        g[u].push_back(i);
    } 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << dp[1] << endl;



}