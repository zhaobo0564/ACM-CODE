#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    if (n % 2) {
        cout << "YES\n";
    } else {
        ll ans = 1;
        for (int i = 1; i <= 50; i++) {
            ans = ans * 2;
            if  (ans == n) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES\n";
    }



}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}