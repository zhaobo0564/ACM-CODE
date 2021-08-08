#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll n, a[N];

bool judge(ll x) {
    for (int i = 1; i <= n; i++) {
        if (x >= a[i]) {
            x--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    ll  l = 1, r = 1e18, ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
}