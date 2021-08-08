#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll n, m, c, s, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ok = 0, base = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] == base) {

        } else {
            ok = 1;
            break;
        }
    }
    if (ok == 0) {
        cout << 0 << endl;
        return;
    }

    m = 0;

    for (int i = 2; i < n; i++) {
        if ((2 * a[i] - a[i - 1] - a[i + 1]) != 0) {
            m = 2 * a[i] - a[i - 1] - a[i + 1];
        }
    }
    m = abs(m);
    c = a[2] - a[1] + m;
    c = c % m;
    int f = 0;
    if (a[1] >= m) {
        cout << -1 << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (((a[i - 1] + c) % m) != a[i]) {
            cout << -1 << endl;
            return;
        } 
    }
    cout << m << " " << c << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}