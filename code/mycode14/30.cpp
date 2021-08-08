#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int n, a[N];

void solve() {
    cin >> n;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x =sqrt(a[i]);
        if (x * x != a[i]) {
            f = 1;
        }
    }
    if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}