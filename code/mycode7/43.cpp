#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
void solve() {
    cin >> n;
    int cnt = n % 10;
    cnt--;
    int ans = cnt  * 10;
    cnt = 0;
    while (n) cnt++, n = n / 10;
    ans += (1 + cnt) * cnt / 2;
    cout << ans   << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}