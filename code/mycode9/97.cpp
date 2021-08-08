#include<bits/stdc++.h>
using namespace std;

int dp[10][10], mp[10][10];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1000;
        dp[i][0] = 1000;
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}