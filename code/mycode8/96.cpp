#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

void solve() {
    ll n; cin >> n;
    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2) {
        cout << 1 << endl;
    } else if (n == 3) {
        cout << 2 << endl;
    } else if (n % 2) {
        cout << 3 << endl;
    } else {
        cout << 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}