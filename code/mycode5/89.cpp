#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

ll n, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        ll maxn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxn = max(a[i], maxn);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= a[i - 1]) {

            } else {
                ans += a[i - 1] - a[i];
            }
        }
        cout << ans << endl;
    }
}