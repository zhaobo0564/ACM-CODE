#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int dp[N], a[N], b[N];

int main() {
    int n, t ;
    scanf("%d %d",&t, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = t; j; j--) {
            if (j - a[i] >= 0)
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t] << endl;
}