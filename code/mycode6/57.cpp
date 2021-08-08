#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a, b, c, d;

    cin >> a >> b >> c >> d;

    ll l = max(a, c);
    ll r = min(b, d);
    if (l <= r) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}