#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
int n, k, a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;

    for (int i = 2; i <= n; i++) {
        if (a[i] < k) {
            int cnt = k - a[i];
            ans += cnt / a[1];
        }
    } 
    cout << ans << endl;


}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}