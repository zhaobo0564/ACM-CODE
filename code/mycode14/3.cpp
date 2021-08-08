#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll; 


void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1 || x == 3) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}