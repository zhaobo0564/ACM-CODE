#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int ans = n - r + m - c;
    ans = max(ans, r - 1 + c - 1);
    ans = max(ans, r - 1 + m - c);
    ans = max(ans, n - r + c - 1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}