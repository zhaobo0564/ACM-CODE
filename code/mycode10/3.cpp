#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int sum = 9;
    if (n == 1) {
        cout << 9 << endl;
    } else if (n == 2) {
        cout << 98 << endl;
    } else {
        cout << 989;
        sum = 0;
        for (int i = 1; i <= n - 3; i++) {
            cout << sum;
            sum++;
            if (sum > 9) sum = 0;
        }
        cout << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}