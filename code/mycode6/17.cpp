#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;
ll n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll cnt = 0, ans = 0, cat = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            cnt += a[i];
        } else {
            if (cnt + a[i] <= 0) {
                a[i] += cnt;
                cnt = 0;
            } else {
               
                cnt += a[i]; a[i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
       // cout << a[i] << " ";
        if (a[i] < 0) ans += abs(a[i]);
    }
   // cout << endl;
    cout << ans << endl;
    
}




int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}