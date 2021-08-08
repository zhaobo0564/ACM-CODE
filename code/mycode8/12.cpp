#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll n, a[N], b[N], c[N];




void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 0;
    }
    b[n + 1] = 0;

    ll begin = 0, end = 0;
    for (int i = 1; i < n; i++) {
        a[i] -= end;
        if (a[i + 1] - end> a[i]) {
            ll cat = a[i + 1] - end - a[i];
            end += cat;
        } else {
            ll cat = a[i] - a[i + 1] + end;
            b[1] += cat;
            b[i + 1] -= cat;
        }
    }
    a[n] -= end;

    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        a[i] -= b[i];
        //cout << a[i] << " ";
    }
    //cout << endl;

    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
  

    
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}