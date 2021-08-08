#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;

int main() {
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    ll l = max(a, c);
    ll r = min(b, d);

    if (r < l) {
        printf("0/1\n");
    } else {
        ll cnt = r - l + 1;
        ll cat = b - a + 1;
        ll dog = d - c + 1;
        ll ans = cat * dog;
        ll gcd = __gcd(cnt, ans);
        printf("%lld/%lld\n", cnt / gcd, ans / gcd);
    }
    
}