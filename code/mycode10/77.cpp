#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;

typedef long long ll;

ll n, a[N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (int j = i; j; j--) {
            if (a[j] < a[i]) {
                break;
            }
            cnt++;
        }
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                break;
            }
            cnt++;
        }
        ans = max(ans, a[i] * cnt);
    }
    cout << ans << endl;
}