#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

ll a[N], b, k, n;

int main() {
    cin >> n >> b >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b > a[i]) {
            int cnt = 1;
            for (int j = 1; j <= n; j++) {
                if (j == i) continue;
                if (a[j] < k) {
                    cnt++;
                } else if (a[j] == k) {
                    cnt++;
                    break;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        } else if (b == a[i]) {
            ans = max(ans, 1);
        }
    }
    cout << ans << endl;
}