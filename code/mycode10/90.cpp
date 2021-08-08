#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    for (int i = 0; i <= 1000; i++) {
        int sum = 2020 * i;
        if (n >= sum) {
            int cnt = n - sum;
            if (cnt % 2021 == 0) {
                cout << "YES\n";
                return;
            } 
        }
    }
    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}