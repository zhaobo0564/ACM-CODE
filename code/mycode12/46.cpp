#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;
int a[N], vis[N];
const int mod = 1e9 + 9;
ll fn[N];

int main() {
    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * i;
        fn[i] %= mod;
    }
    int t; scanf("%d", &t);
    ll ans = 1;
    while (t--) {
        ans = 1;
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            vis[a[i]] = 0;
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int pos = a[i];
            int cnt = 0;
            if (vis[pos] == 0) {
                res++;
            } else {
                continue;
            }
            while (vis[pos] == 0) {
                cnt++;
                vis[pos] = 1;
                pos = a[pos];
            }
            if (cnt == 1) res--;
            if (cnt == 2) cnt--;
            ans = ans * cnt % mod;

        }
        ans = ans * fn[res] % mod;
        cout << ans << endl;
    }
}