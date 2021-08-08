#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, p;

ll ksm(ll x, ll y) {
    x = x % p;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % p;
        }
        x = x * x % p;
        y = y / 2;
    }
    return base % p;
}

int main() {
    int t; cin >> t;
    while (t--) {
        

        cin >> a >> b >> p;
        ll x = ((a * a % p  - 4 * b %p) %p + p) % p;
        if (p == 2) {
            if (b % 2 == 0) {
                puts("Yes");
            } else {
                if ((1 + a) % 2) {
                    puts("Yes");
                } else {
                    puts("No");
                }
            }

        } else {
            cout << x << endl
            cout << ksm(a, (p - 1) / 2) << endl;
            if (ksm(a, (p - 1) / 2)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
}