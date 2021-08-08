#include<bits/stdc++.h>
using namespace std;
const int N = 4007;

char s[N], t[N];
int next_s[N][2], next_t[N][2];
int n, m, vis[10];
int dp[N][N];

int dfs(int i, int j) {
    if (i > n && j > m) {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 1e7;
    int nxs = next_s[i][0];
    int nxt = next_t[j][0];
    ans = min(ans, dfs(nxs, nxt) + 1);
    nxs = next_s[i][1], nxt = next_t[j][1];
    ans = min(ans, dfs(nxs, nxt) + 1);
    return dp[i][j] = ans;
}

void print(int i, int j) {
    if (i > n && j > m) return;
    int nxs0 = next_s[i][0];
    int nxt0 = next_t[j][0];
    int nxs1 = next_s[i][1];
    int nxt1 = next_t[j][1];
    if (dfs(i, j) == dfs(nxs0, nxt0) + 1) {
        printf("0");
        print(nxs0, nxt0);
    } else {
        printf("1");
        print(nxs1, nxt1);
    }
}

int main() {
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    vis[0] = n + 1, vis[1] = n + 1;
    for (int i = n; i; i--) {
        next_s[i][0] = vis[0];
        next_s[i][1] = vis[1];
        vis[s[i] - '0'] = i;
    }
    next_s[0][0] = vis[0];
    next_s[0][1] = vis[1];
    next_s[n + 1][0] = next_s[n + 1][1] = n + 1;

    vis[0] = m + 1, vis[1] = m + 1;
    for (int i = m; i; i--) {
        next_t[i][0] = vis[0];
        next_t[i][1] = vis[1];
        vis[t[i] - '0'] = i;
    }
    next_t[0][0] = vis[0];
    next_t[0][1] = vis[1];
    next_t[m + 1][0] = next_t[m + 1][1] = m + 1;
    memset(dp, -1, sizeof(dp));
   // int ans = dfs(0, 0);
    print(0, 0);
    puts("");
    

}