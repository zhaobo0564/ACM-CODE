#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

ll a[N], n;

bool judge() {
    ll d = a[2] - a[1];
    int f = 0, ans = 0;
    for (int i = 3; i <= n; i++) {
        if (a[i] - a[i - 1] != d) {
            f = 1;
            break;
        }
    }
    if (f == 0) ans++;
    if (a[2] % a[1] == 0) {
        ll q = a[2] / a[1];
        f = 0;
        for (int i = 3; i <= n; i++) {
            if (a[i] % a[i - 1] == 0) {
                if (q == a[i] / a[i - 1]) {

                } else {
                    f = 1;
                    break;
                }
            } else {
                f = 1;
                break;
            }
        } 
        if (f == 0) ans++;
    }
    d = max(a[2], a[1]) % min(a[2], a[1]);
  //  cout << d << endl;
    f = 0;
    for (int i = 3; i <= n; i++) {
        if (max(a[i], a[i - 1]) % min(a[i], a[i - 1]) == d) {

        } else {
            f = 1;
            break;
        }
    }
    if (f == 0) ans++;
    if (ans) return true;
    return false;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if ( judge()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}