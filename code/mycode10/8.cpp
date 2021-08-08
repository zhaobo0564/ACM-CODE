#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll n, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[1] << " " << 0 << endl;
        return 0;
    }
    ll g = a[2] - a[1];
    for (int i = 3; i <= n; i++) {
        g = __gcd(g, a[i] - a[i - 1]);
    }
    g = abs(g);
    if (g == 0) g = a[1];
    if (a[1] >= g) {
        ll cnt = a[1] / g;
        if (a[1] % g) {
            cnt++;
        }
        ll ans = g * cnt - a[1];
        cout << g << " " << ans << endl;

    } else {
        
        cout << g << " " << g - a[1] << endl;
    }
}