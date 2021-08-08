#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

void solve() {
    ll a, b, n;
    cin >> n >> a >> b;

    if (a * 2 <= b) {
        cout << n * a << endl;
    } else {
        ll cnt = n / 2;
        ll cat = n % 2;
        cnt = cnt * b;
        
        cnt += a * cat;
        cout << cnt << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;

    while (t--) {
        solve();
    }
}