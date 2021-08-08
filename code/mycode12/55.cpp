#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 1e5 + 7;
int n, a[N], vis[200 * N], dp[N * 200];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            if ((sum & a[j])) break;
            sum += a[j];
            vis[sum] = 1;
        }
    }
    int m = 1 << 24;
    for (int i = 0; i < m; i++) {
        if (vis[i]) dp[i] = i;
        for (int j = 0; j < 24; j++) {
            dp[i] = max(dp[i], dp[i ^ (1 << j)]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (vis[i]) {
        //    cout << i << " " << (i ^ (m - 1)) << " " << dp[i ^ (m - 1)] << endl;
            ans = max(ans, dp[i ^ (m - 1)] + i); 
        }
        
    }
    cout << ans << endl;
    return 0;
}