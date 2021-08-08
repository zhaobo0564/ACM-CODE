#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll w[N], c[N], n, m;

multiset<ll> s;

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
    }
    sort(w + 1, w + n + 1);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &c[i]);
        s.insert(c[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto it = s.begin();
        if (w[i] >= *it) {
            ans++;
            s.erase(it);
        }
    }
    cout << ans << endl;
}