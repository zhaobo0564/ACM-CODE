#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
ll ans = 0, a, b, n, c[N];
int vis[N];

ll lcm(ll x, ll y) {
    return x * y / __gcd(x, y);
}

void dfs(ll x, int sum, int p) {
    if (sum % 2 == 0) {
        ans += b / x - (a - 1) / x;
    } else {
        ans -= (b / x - (a - 1) / x);
    }

    for (int i = p; i <= n; i++) {
        if (lcm(x, c[i]) <= b) {
            
            dfs(lcm(x, c[i]), sum + 1, i + 1);
            //vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cin >> a >> b;
    dfs(8, 0, 1);
    cout << ans << endl;
}