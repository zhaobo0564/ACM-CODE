#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll;

ll n, a[N];

void solve() {
    cin >> n;
    ll maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    int ans = -1;

    a[0] = 1e10, a[n + 1] = 1e10;
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxn) {
            if (a[i - 1] < maxn || a[i + 1] < maxn) {
                ans = i;
                break;
            }
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