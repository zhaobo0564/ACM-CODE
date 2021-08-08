#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    int l = 1, r = n;
    a[n + 1] = -1;
    while (a[l] == 0)l++;
    while (a[r] == 0) r--;
    if (r <= l) {
        cout << 0 << endl;
    } else {
        int ans = 0, cnt = 0;
        for (int i = l; i <= r; i++) {
            if (a[i] == 0) {
                ans++;
            } 
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