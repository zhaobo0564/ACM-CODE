#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll n;

void solve() {
    cin >> n;
    int cnt = n + n;
    for (int i = 1; i <= n; i++) {
        cout << cnt << " ";
        cnt += 2;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}