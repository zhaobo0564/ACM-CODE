#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

vector<int> g[N];
int dp[N][2];

void dfs(int u, int fa) {
    dp[u][1] = 1;
    for (int to: g[u]) {
        if (to == fa) {
            continue;
        }
        dfs(to, u);
        dp[u][0] += max(dp[to][0], dp[to][1]);
        dp[u][1] += dp[to][0];
    }
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s, 0);
    printf("%d\n", dp[s][1]);

    

}