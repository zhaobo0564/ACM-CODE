#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int a[N], b[N], n, x;

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] + b[i] > x) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}