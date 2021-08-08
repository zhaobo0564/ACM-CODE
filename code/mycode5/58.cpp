#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, a[1000], b[1000], n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int mina = INT_MAX, minb = INT_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mina = min(mina, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            minb = min(minb, b[i]);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == mina && b[i] == minb) {

            } else if(a[i] == mina) {
                ans += 1ll*(b[i] - minb);
            } else if (b[i] == minb) {
                ans += 1ll*(a[i] - mina);
            } else {
                int cnt = max(a[i] - mina, b[i] - minb);
                ans += 1ll*cnt;
            }
        }
        cout << ans << endl;
    }
}