#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

char mp[N][N];

int n, m;

int dp[N][N][2];

bool judge(int x, int y) {
    if (x < 0 || y < 0 || x > n || y > m) {
        return false;
    }
    return true;
}

int dfs(int x, int y, int f) {
    if (x == n && y == m) {
        return 0;
    }
    if (dp[x][y][f] != -1) return dp[x][y][f];
    int ans = -1e7, ans1 = 1e7, ans2 = -1e7, ans3 = 1e7;
    
    if (judge(x + 1, y)) {
        if (mp[x + 1][y] == '+') {
            if (f == 0) {
                ans = dfs(x + 1, y, f ^ 1) + 1; 
            } else {
                ans1 = dfs(x + 1, y, f ^ 1) - 1;
            }
        } else {
             if (f == 0) {
                ans = dfs(x + 1, y, f ^ 1) - 1; 
            } else {
                ans1 = dfs(x + 1, y, f ^ 1) + 1;
            }
        }
    }

    if (judge(x, y + 1)) {
        if (mp[x][y + 1] == '+') {
            if (f == 0) {
                ans2 = dfs(x, y + 1, f ^ 1) + 1; 
            } else {
                ans3 = dfs(x, y + 1, f ^ 1) - 1;
            }
        } else {
            if (f == 0) {
                ans2 = dfs(x, y + 1, f ^ 1) - 1; 
            } else {
                ans3 = dfs(x, y + 1, f ^ 1) + 1;
            }
        }
    }
    if (f == 0) {
        return dp[x][y][f] = max(ans, ans2);
    }
    return dp[x][y][f] = min(ans1, ans3);
} 

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &mp[i][j]);
        }
    }
    memset(dp, -1,sizeof(dp));
    int ans = dfs(1, 1, 0);



    if (ans > 0) {
        puts("Takahashi");
    } else if (ans == 0) {
        puts("Draw");
    } else {
        puts("Aoki");
    }
    return 0;

}