#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s, m, sum, a[2000];
bool judge(int x) {
    for (int i = 1; i <= x; i++) {
        a[i] = s / x;
    }
    for (int i = 1; i <= s % x; i++) {
        a[i]++;
    }
    ll cnt = 0, ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += a[i] * cnt;
        cnt += a[i];
    }
    if (ans >= m) return true;
    return false;
}

int main() {
    cin >> s >> m;
    int l = 1, r = s, ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans  - 1<< endl;
 
}