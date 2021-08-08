#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k >= n) {
        ll ans = k / n;
        if (k % n) {
            ans++;
        }
        cout << ans << endl;
    } else {
        ll cnt = n / k;
        if (n % k) {
            cnt++;
        }
        k = k * cnt;
        ll ans = k / n;
        if (k % n) {
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