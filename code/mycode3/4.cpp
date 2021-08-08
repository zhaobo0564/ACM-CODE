#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int ans = 0;
    for (int maxn = 30; maxn >= -30; maxn--) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(0, sum) + a[i];
            ans = max(ans, sum - maxn);
        }
    }
    cout << ans << "\n";
}