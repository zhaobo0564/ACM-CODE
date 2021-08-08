#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        double n, m, x, y;
        cin >> n >> m >> x >> y;
        double ans = (n - m) / (x + y);
        double ans1 = m / (y - x);
        if (ans1 >= 0.0) {
            ans = min(ans, ans1);
        }
        printf("%.6f\n", ans);
    }
}