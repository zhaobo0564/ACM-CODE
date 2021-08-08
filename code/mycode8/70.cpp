#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

ll x[N], n, w;


int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        ll s, t, p;
        
        cin >> s >> t >> p;s++, t++;
        x[s] += p;
        x[t] -= p;
    }
    for (int i = 1; i < N; i++) {
        x[i] += x[i - 1];
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, x[i]);
    }
    if (ans > w) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}