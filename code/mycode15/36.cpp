#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

int n;
ll x[N], y[N];

struct node {
    ll xx, yy, pos;
} a[N], b[N];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        a[i].xx = x[i];
        a[i].yy = y[i];
        a[i].pos = i;
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1, [](node X, node Y) {
        return  X.xx < Y.xx;
    });
    sort(b + 1, b + n + 1, [](node X, node Y) {
        return X.yy < Y.yy;
    });
    if (a[1].pos == b[1].pos && a[n].pos == b[n].pos) {
        ll ans = max(abs(a[1].xx - a[n - 1].xx), abs(a[n].xx - a[2].xx));
        ans = max({ans, b[n - 1].yy - b[1].yy, b[n].yy - b[2].yy});
        cout << ans << endl;
    } else {

        if (b[n].yy - b[1].yy > a[n].xx - a[1].xx) {
            cout << max({a[n].xx - a[1].xx, b[n].yy - b[2].yy, b[n - 1].yy - b[1].yy}) << endl;
        } else {
            cout << max({b[n].yy - b[1].yy, a[n].xx - a[2].xx, a[n - 1].xx - a[1].xx}) << endl;
        }
    }
    return 0;
}