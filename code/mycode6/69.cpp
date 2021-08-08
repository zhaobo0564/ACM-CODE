#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll n, a[N], sum[N];

unordered_map<ll, int> vis;

void solve() {
    cin >> n;
    vis.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll now = 0, ans = 0;

    for (int i = 1; i <= n; i++) {
        now += a[i];
        if (now == 0) {
            ans++;
            vis.clear();
            now = a[i];
        } else {
            if (vis[now]) {
                now = a[i];
                ans++;
                vis.clear();
            }
        } 
        vis[now]++;

    }
    cout << ans << endl;

}


int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}