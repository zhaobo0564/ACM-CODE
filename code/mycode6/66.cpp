#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    if (n <= 2) {
        cout << 1 << endl;
    } else {
        ans++;
        n -= 2;
        while (n > 0) {
            n -= x;
            ans++;
        }
        cout << ans << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}