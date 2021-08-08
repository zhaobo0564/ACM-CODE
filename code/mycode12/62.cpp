#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 7;

int miu[N], vis[N], n;
ll sum[N];

void mobius() {
    for (int i = 1; i < N; i++) vis[i] = 0, miu[i] = 1;
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        miu[i] = -1;
        for (int j = 2 * i; j < N; j += i) {
            vis[j] = 1;
            if ((j / i) % i == 0) miu[j] = 0;
            else miu[j] *= -1;
        }
    }
}

ll work(int a, int b) {
    int m = min(a, b);
    ll ans = 0;
    for (int i = 1, l; i <= m; i = l + 1) {
        int la = a / (a / i);
        int lb = b / (b / i);
        if (la > lb) {
            l = lb;
          
            ans += 1ll*(a / i) * (b / i) * (sum[l] - sum[i - 1]);
        } else {
            l = la;
    
            ans += 1ll*(a / i) * (b / i) * (sum[l] - sum[i - 1]);
        }
    }
    return ans;
}

int main() {
    mobius();
    for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1] + miu[i];
    }
    scanf("%d", &n);
    while (n--) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        a = a / d;
        b = b / d;
        printf("%lld\n", work(a, b));
    }
    
}