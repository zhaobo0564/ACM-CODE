#include<bits/stdc++.h>

using namespace std;

int a[100], n, dp[100][100];

int dfs(int l, int r) {
    if (l > r) return  dp[l][r] = 0;
    int ans = 0;
    if (dp[l][r] != -1) return dp[l][r];
    for (int i = l; i <= r; i++) {
        int lans = dfs(l, i - 1);
        int rans = dfs(i + 1, r);
        if (lans == 0 && rans == 0) {
            ans = max(ans, a[i]);
        } else if (lans == 0) {
            ans =  max(ans, a[i] + rans);
        } else if(rans == 0) {
            ans = max(ans, a[i] + lans);
        } else {
            ans = max(ans, rans * lans + a[i]);
        }
    }
    return dp[l][r] = ans;
}

void dfs1(int l, int r) {
    if (l > r) return;
    for (int i = l; i <= r; i++) {
        if (dp[l][i - 1] == 0 && dp[i + 1][r] == 0) {
            if (dp[l][r] == a[i]) {
                cout << i << " ";
                dfs1(l, i - 1);
                dfs1(i + 1, r);
                return;
            }
        } else if (dp[l][i - 1] == 0) {
            if (dp[l][r] == dp[i + 1][r]  + a[i]) {
                cout << i << " ";
                dfs1(l, i - 1);
                dfs1(i + 1, r);
                return;
            }
        } else if (dp[i + 1][r] == 0) {
            if (dp[l][r] == dp[l][i - 1] + a[i]) {
                cout << i << " ";
                dfs1(l, i - 1);
                dfs1(i + 1, r);
                return;
            }
        } else {
            if (dp[l][r] == dp[l][i - 1] * dp[i + 1][r] + a[i]) {
                cout << i << " ";
                dfs1(l, i - 1);
                dfs1(i + 1, r);
                return;
            }
        }

    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, n) << "\n";
    dfs1(1, n);

}