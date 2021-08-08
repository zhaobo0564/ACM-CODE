#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
ll dp[N][2], n, ans;
vector<int> g[N];

void dfs(int u, int fa) {
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        ans += dp[to][1] * dp[u][0];
        ans += dp[to][0] * dp[u][1];
        ans += dp[u][1];
        ans += dp[to][1];
        
      //  cout << "to =  "<< to <<" " << ans << endl;
        dp[u][0] += dp[to][1];
        dp[u][1] += dp[to][0] + 1;
    }
    
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}

/*
8
1 2
2 3
2 4
1 5
5 6
5 7
1 8
*/