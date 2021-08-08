#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;
int a[N], n, t, m;

bool judge(int x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1ll*(a[i] - x);
    }
    ll cnt = m - x;
    if (cnt * 1ll*(n - 1) >= sum) return true;
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        int r = 1e9 + 7;
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            r = min(r, a[i]);
            maxn = max(maxn, a[i]);
        }
        int l = 0, ans, R1 = r;
        while (l <= r) {
            int m = (l + r) / 2;
            if (judge(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        int L1 = ans;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (sum >= m) {
                break;
            }
        }
        l = max(0, m - sum);
        r = m - maxn;
        cout << L1 << " " << R1 << endl;
        cout << l << " " << r << endl;
    
        



    }
}