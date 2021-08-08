#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
ll n, a[N], sum[N], b[N], dp[N];

vector<int> v;

int dfs(int p) {
    if (p == n) {
        return 1;
    }
    if (dp[p] != -1) return dp[p];
    int ans = 0;
    if (sum[p] >= b[p + 1])
        ans = max(ans, dfs(p + 1));
    return dp[p] = ans;
}

void solve() {
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        dp[i] = -1; 
    }
    dp[0] = -1;
    dp[n + 1] = -1;
    b[n + 1] = b[0] = 0;
    sum[0] = sum[n + 1] = 0;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++) {
        int p = lower_bound(b + 1, b + n + 1, a[i]) - b;
        if (b[p] == a[i]) {

            int ans = dfs(p);
            if (ans) {
                v.push_back(i);
            }
        }
    }
    cout << v.size() << endl;
    for (int i: v) {
        cout << i << " ";
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