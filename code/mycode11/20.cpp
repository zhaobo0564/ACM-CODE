#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n;


int main() {
    cin >> n;
    n = n + n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll x = i;
            ll y = n / i;
            ll z = x + y - 1;
            if (z % 2 == 0) {
                ans++;
            }

        }
    }
    cout <<2 * ans << endl;
}