#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;

int main () {
    scanf("%d", &t);
    while (t--) {
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        ll ans =  a * a - b * b - c*c + d * d;
        if (ans < 0) {
            puts("AB//CD");
        } else {
            puts("AB//DC");
        }
    }
}