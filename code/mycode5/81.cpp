#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>big, small;

const int N = 1e5 + 7;
ll cnt[N];

int main() {
    int n, m, d;
    scanf("%d %d %d", &n, &d, &m);
    for (int i = 1; i <= n; i++) {
        ll x; scanf("%lld", &x);
        if (x > m) {
            big.push_back(x);
        } else {
            small.push_back(x);
        }
    }
    sort(big.begin(), big.end());
    sort(small.begin(), small.end());
    reverse(big.begin(), big.end());
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < small.size(); i++) {
        cnt[i + 1] = cnt[i] + small[i];
    }
    int total = (int)big.size();
    for (int i = 0; i < big.size(); i++) {
        sum += big[i];
        if ((i) * d + i + 1 > n) break;
        int days = (i) * d ;
   
        ll cn = sum;
        ll cat = total - 1 - i;
        days -= cat;
        if (days < 0) {
            days = 0;
        }
        if (days < small.size())
            cn += cnt[(int)small.size()] - cnt[days];
        ans = max(cn, ans);
    }
    ans = max(ans, cnt[(int)small.size()]);
    printf("%lld\n", ans);
}