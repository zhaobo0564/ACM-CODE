#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
int a[N];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    
    for (int i = 2; i <= n; i++) {
        int maxn = max(a[i - 1], a[i]);
        int minn = min(a[i - 1], a[i]);
        if (minn * 2 >= maxn) {

        } else {
            while (minn * 2 < maxn) {
                minn = minn * 2;
                ans++;
            }
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