#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll w[N], v[N], n, m;
ll ans = 0;
void dfs(int p, ll sum, ll all) {
    if (n < all) return;
    if (p > m) {
        ans = max(ans, sum);
        return;
    }
    dfs(p + 1, sum + w[p] * v[p], all + w[p]);
    dfs(p + 1, sum, all);
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld %lld", &w[i], &v[i]);
    }
    dfs(1, 0, 0);
    cout << ans << endl;
}