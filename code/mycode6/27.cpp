#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll x, y, k;

void solve() {
    cin >> x >> y >> k;

    ll cnt = k + k;
    ll cat = k * y;
    ll sum = k + cat;
    x--;
    sum--;
    ll ans = sum / x;
    if (sum % x) {
        ans++;
    }
    cout << ans + k << endl;
    
}



int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}