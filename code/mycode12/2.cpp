#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    ll k; cin >> k;
    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= k; j++) {
            if (i * j > k) break;
            for (ll z = 1; z <= k; z++) {
                if (i * j * z <= k) {
                    ans++;
                } else {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

