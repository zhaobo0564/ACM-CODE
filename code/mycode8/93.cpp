#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll p, s;
    cin >> s >> p;
    for (ll i = 1; i * i <= p; i++) {
        if (p % i == 0) {
            ll j = p / i;
            if (i + j == s) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}