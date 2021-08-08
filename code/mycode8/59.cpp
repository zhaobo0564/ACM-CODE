#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int sum[N], n, vis[N];

void init() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; j < N; j += i) {
            if (i * i <= j) {
                sum[j] += i;
                if (j / i != i) {
                    sum[j] += (j / i);
                }
            }
        } 
    }
}

vector<int> g[N];

int dp[N];

int dfs(int u) {
    int ans = 0;
    if (dp[u] != -1) return dp[u];
    for (int to: g[u]) {
        ans = max(ans, dfs(to) + 1);
    }
    return dp[u] = ans;
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        sum[i] -= i;
        if (sum[i] >= i) continue;
        g[i].push_back(sum[i]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans + 1 << endl;
    
    
    
    
}