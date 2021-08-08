#include<bits/stdc++.h>
using namespace std;

int main() {
    int w, h, u, d, u1, d1;
    cin >> w >> h >> u >> d >>u1 >>d1;
    int ans = w;
    while(h) {
        ans += h;
        if (h == d) {
            ans -= u;
            ans = max(ans, 0);
        }
        if (h == d1) {
            ans -= u1;
            ans = max(ans, 0);
        }
        h--;
    }
    cout << ans << endl;
}