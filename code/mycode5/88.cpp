#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;
ll n, k, d, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        ll maxn = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            cin >>  a[i];
            maxn = max(maxn, a[i]);
        }
        if (k % 2 == 0) {
            ll maxn1 = LLONG_MIN;
            for (int i = 1; i <= n; i++) {
                a[i] = maxn - a[i];
                maxn1 = max(maxn1, a[i]);
            }
            for (int i = 1; i <= n; i++) {
                cout << maxn1 - a[i] << " ";
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n; i++) {
                cout << maxn - a[i] << " ";
            }
            cout << endl;
        }
    }
}