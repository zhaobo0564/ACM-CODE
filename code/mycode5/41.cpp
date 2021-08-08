#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 7;

int t, n, k, z;
ll a[N], sum[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &k, &z);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        ll maxn = 0;
        maxn = sum[k + 1];
        for (int i = 2; i <= k; i++) {
            int cnt = k - i + 1;
            if (cnt >= z * 2) {
                ll ans = sum[i] + (a[i] + a[i - 1]) * z; 
                cnt -= 2 * z;
                ans += sum[i + cnt] - sum[i];
              //  cout << "ans " << ans << " " << i <<endl;
                maxn = max(ans, maxn);
            } else {
                ll ans = 0;
                int cn = cnt;
                cnt = cnt / 2;
                ans += sum[i] + (a[i] + a[i - 1]) * cnt;
                if (cn % 2)
                    ans += max(a[i - 1], a[i + 1]);
                maxn= max(ans, maxn);
            }
        }
        printf("%lld\n", maxn);

    }
}