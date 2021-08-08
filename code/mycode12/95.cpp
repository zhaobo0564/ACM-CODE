#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void solve() {
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if ((k1 + k2) >= 2 * w && (2 * n - (k1 + k2)) >= 2 * b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
}

int main() {

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}