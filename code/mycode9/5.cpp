#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll a[N], b[N], n, m, c[N], p;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] * 85 + b[i] * 15;
    }
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    ll ans = (c[m] - p * 15);
    if (ans % 85 == 0) {
        ans = ans / 85;
    } else {
        ans = ans / 85;
        ans++;
    }

    cout << max(0, ans) << endl;

}