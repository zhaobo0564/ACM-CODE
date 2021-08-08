#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;



ll n, a[N], k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[0] = 0;
    ll sum = a[n];
    int i = n - 1;
    while(k--) {
        sum += a[i];
        i--;
    }
    cout << sum  << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}