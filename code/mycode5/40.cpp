#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, t;

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &l, &r);
        ll cnt = l * 2;
        if (cnt > r) {
            puts("-1 -1");
        } else {
            printf("%lld %lld\n", l, cnt);
        }
    }
}