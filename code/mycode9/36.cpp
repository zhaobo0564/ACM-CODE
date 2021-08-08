#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
    ll a, b, x[2], y[2];
    while (~scanf("%lld", &a)) {
        scanf("%lld %lld %lld %lld %lld",&b, &x[0], &x[1], &y[0], &y[1]);
        ll sum = ((a + 1)  * a) / 2;
        sum = sum % mod;
        ll sum1 = ((b + 1) * b) / 2;
        sum1 = sum1 % mod;
        ll ans = sum * sum1 % mod;
        ll cn = (x[1] - x[0]) * (y[1] - y[0]) % mod;
        ll cnt = a * b % mod;
        cn = cn * cnt % mod;
        ans = (ans + cn) % mod;
        if (a <= x[0] || b <= y[0]) {
            printf("%lld\n", ans);
        } if (x[0] <= a && y[0] <= b && x[1] >= a && y[1] >= b) {
            ll l = (a - x[0]);
            ll r = (b - y[0]);
            l = (l + 1) * l / 2;
            l = l % mod;
            r = (r + 1) * r / 2;
            r = r % mod;
            l = l * r % mod;
            ans = (ans - l + mod) % mod;
            printf("%lld\n", ans);
        } else if (a > x[1] && b > y[1]) {
            ll l = (x[1] - x[0]);
            ll r = (y[1] - y[0]);
            l = (l + 1) * l / 2;
            l = l % mod;
            r = (r + 1) * r / 2;
            r = r % mod;
            l = l * r % mod;
            ans = (ans - l + mod) % mod;
            ll cnt = (a - x[1]) * (b - y[1]) % mod;
            ll area = (x[1] - x[0]) * (y[1] - y[0]) % mod;
            area = (cnt % mod * area % mod) % mod;
            ans = (ans - area + mod) % mod;
            l = (x[1] - x[0]), r = (y[1] - y[0]);
            l = (l + 1) * l / 2;
            l = l % mod;
            l = l * r % mod;
            l = l * (b - y[1]) % mod;
            ans = (ans - l + mod) % mod;
            r = (r + 1) * r / 2;
            r = r % mod;
            r = r * (x[1] - x[0]) % mod;
            r = r * (a - x[1]) % mod;
            ans = (ans - r + mod) % mod;
            printf("%lld\n", ans);
        } else if (a > x[1]) {
            ll l = (x[1] - x[0]), r = (b - y[0]);

            l = (l + 1) * l / 2;
            l = l % mod;
            r = (r + 1) * r / 2;
            r = r % mod;
            l = l * r % mod;
            ans = (ans - l + mod) % mod;
            l = (x[1] - x[0]), r = b - y[0];
            r = (r + 1) * r / 2;
            r = r % mod;
            r = r * l % mod;
            r = r * (a - x[1]) % mod;
            ans = (ans - r + mod) % mod;
            printf("%lld\n", ans);

        } else {
            ll l = a - x[0], r = y[1] - y[0];
            l = (l + 1) * l / 2;
            l = l % mod;
            r = (r + 1) * r / 2;
            r = r % mod;
            l = l * r % mod;
            ans = (ans - l + mod) % mod;
            l = a - x[0], r = y[1] - y[0];
            l = (l + 1) * l / 2;
            l = l % mod;
            l = l * r % mod;
            l = l * (b - y[1]) % mod;
            ans = (ans - l + mod) % mod;
            printf("%lld\n", ans);
        } 
        
        
    }
}