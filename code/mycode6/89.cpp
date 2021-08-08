#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll n, a[N], odd[N], even[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            even[i] = even[i - 1] + a[i];
            odd[i] = odd[i - 1];
        } else {
            odd[i] = odd[i - 1] + a[i];
            even[i] = even[i - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll od = odd[i - 1];
        ll ev = even[i - 1];
        od += even[n] - even[i];
        ev += odd[n] - odd[i];
        //cout << ev << " " << od << endl;
        if (ev == od) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;

    while (t--) {
        solve();
    }
}