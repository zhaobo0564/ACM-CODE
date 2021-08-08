#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        ll cnt = abs(xx - x + 1);
        ll cn = abs(yy - y + 1);
        cout << cnt * cn << endl;
    }
}