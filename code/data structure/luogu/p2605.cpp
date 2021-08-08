#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 7;

ll n, k, d[N], c[N], s[N], w[N];

ll dfs(int p, int sum) {
    if (p > n) {
        if (sum <= k) return 0;
        return 1e9;
    }

    ll ans = 1e18;
    

    
}

int main() {
    scanf("%lld %lld", &n, &k);
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &d[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
    }

    ll ans = dfs(1, 0);
    cout << ans << endl;



}