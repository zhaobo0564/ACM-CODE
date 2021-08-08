#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

ll a[N], n, m;

bool judge(int x) {
    int cnt = 1, last = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] - a[last] >= x ) {
            cnt++;
            last = i;
        }
    }
    if (cnt >= m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = 1e9, ans = 0;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}