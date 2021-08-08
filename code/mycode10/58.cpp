#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
typedef long long ll;
ll a[N], n, k, vis[2 * N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) {
            a[i] = vis[i];
            n = i;
        } else {
            break;
        }
    }
    ll ans = 0;
    while (1) {
        ll minn = N, pos;
        for (int i = 0; i <= n; i++) {
            if (minn > a[i]) {
                minn = a[i];
                pos = i;
            }
        }
        if (minn >= k) {
            ans += (n + 1) * k;
            break;
        } else {
            k -= minn;
            ans += minn * (n + 1);
        }
        for (int i = 0; i < pos; i++) {
            a[i] -= minn;
        }
        n = pos - 1;
    }
    cout << ans << endl;

}