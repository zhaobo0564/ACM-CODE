#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
typedef long long ll;

char s[N];
int a[N];
ll n;
int dp[N][2];

int dfs(int p, int f) {
    if (p == n) return 0;
    int ans = 0;
    if (dp[p][f] != -1) return dp[p][f];
 
    if ((a[p + 1] ^ f) == 1) {
        ans += dfs(p + 1, f ^ 1) + 1;
    } 
    return dp[p][f] = ans;
}

int fn[N][2];

int dfs1(int p, int f) {
    if (p == 0) return 0;
    if (fn[p][f] != -1) return fn[p][f];
    int ans = 0;
    if ( (a[p] ^ f) == 0) {
        ans += dfs1(p - 1, f ^ 1) + 1;
    }
    return fn[p][f] = ans;
}

void solve() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') a[i] = 0;
        else a[i] = 1;
    }
    for (int i = 0; i <= n + 1; i++) {
        fn[i][0] = fn[i][1] = -1;
        dp[i][0] = dp[i][1] = -1;
    }
    for (int i = 0; i <= n; i++) {
        cout << dfs(i, 0) + dfs1(i, 0) + 1 << " ";
    } 
    cout << endl;
}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}