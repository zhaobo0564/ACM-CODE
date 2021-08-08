#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, d;
        cin >> a >> b >> d;
        if (a < b) swap(a, b);
        ll cnt = a / (d + 1);
        if (a % (d + 1)) cnt++;
        if (b >= cnt) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}