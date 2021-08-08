#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n; scanf("%lld", &n);
    long long lastx = 0, lasty = 0, lastt = 0;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int t, x, y; 
        scanf("%lld %lld %lld", &t, &x, &y);
        long long len = abs(lastx - x) + abs(lasty - y);
        t = t - lastt;
        if (t >= len && ((t - len) % 2) == 0) {

        } else {
            f = 1;
        }
        lastx = x, lasty = y, lastt = t + lastt;
    }
    if (f == 0) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int32_t main() {
    int t; scanf("%lld", &t);
    while (t--) {
        solve();
    }
}