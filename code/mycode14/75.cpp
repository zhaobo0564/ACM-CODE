#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;

ll ans = LLONG_MAX;

int t = 1;

map<ll, ll> vis;

void dfs(ll base, ll step) {

    if (base <= x) {
        ans = min(ans, step + x - base);
        return;
    }
    if (vis[base] == 0) vis[base] = step;
    else if (step >= vis[base]) return;
    ans = min(ans, step + base - x);
    if (base % 2 == 0) {
        dfs(base / 2, step + 1);
    } else {
        dfs((base + 1) / 2, step + 2);
        dfs((base - 1) / 2, step + 2); 
    }
}

int main() {

    cin >> x >> y;
    dfs(y, 0);
    cout << ans << endl;
}