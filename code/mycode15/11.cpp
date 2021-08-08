#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    ll cnt = n / 6;
    ll ans = min(3 * a * cnt, 2 * b * cnt);
    cnt = n % 6;
 //   cout << "cnt " << cnt << endl;
    ll cat = INT_MAX;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            int sum = i * 2 + j * 3;
            if (sum >= cnt) {
                cat = min(cat, 1ll*(i * a + j * b));
            }
        }
    }
    printf("%lld\n", ans + cat);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}