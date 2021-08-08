#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll ans = 0, r;
    for (ll l = 1; l <= n; l = r + 1 ) {
        r = n / (n / l);
        ans += (r - l + 1) * (n / l);
    }
    cout << ans << endl;
}