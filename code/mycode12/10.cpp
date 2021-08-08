#include<bits/stdc++.h>
using namespace std;
const int N = 300;
int n, u, v, a[N];

void solve() {
    // u down, v left
    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxn = 0;
    for (int i = 2; i <= n; i++) {
        maxn = max(maxn, abs(a[i] - a[i - 1]));
    }
    if (maxn > 1) {
        cout << 0 << endl;
    } else if (maxn == 1) {
        cout << min(u, v) << endl;
    } else {
        cout << min(u + v, v + v) << endl;
    }
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}