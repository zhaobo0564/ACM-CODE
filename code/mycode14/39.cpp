#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (k >= a[i]) {
            k -= a[i];
            cnt += a[i];
            a[i] = 0;

        } else {
            a[i] -= k;
            cnt += k;
            k = 0;
            break;
        }
    }
    a[n] += cnt;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}