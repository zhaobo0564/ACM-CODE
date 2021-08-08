#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, a[N];
ll sum[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll maxn = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i] + sum[i - 1];
        maxn = max(maxn, 1ll*a[i]);
        printf("%lld\n", sum[i] + 1ll * i * maxn);
    }
    return 0;

}
