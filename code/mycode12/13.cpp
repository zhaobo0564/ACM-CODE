#include<bits/stdc++.h>
using namespace std;
const int N = 5007;
typedef long long ll;

int s[N], n, add[N];

void work(int l, int r) {
    r = min(r, n);
    l = max(1, l);
    if (l > r) return;
    for (int i = l; i <= r; i++) {
        add[i]++;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        add[i] = 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = max(1, s[i] - add[i]);
        if (add[i]) {
            if (s[i] > add[i]) {
                work(s[i] + i - add[i] + 1, s[i] + i);
            } else {
                work(i + 1, s[i] + i);
                add[i] -= s[i];
                add[i + 1] += add[i];
            }
            
        }
        if (x != 1) {
            if (i + x > n) {
                ans += x;
                ans--;

                work(i + 2, n);

            } else {
               ans += x;
               ans--;
               work(i + 2, i + x);
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
    return 0;
}

// 16
// 2 1 6 3 2 9 2 8 5 10 3 2 5 6 3 10
