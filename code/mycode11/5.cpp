#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll q, d;

bool judge(ll x) {
    while (x) {
        if ((x % 10) == d) {
            return true;
        }
        x = x / 10;
    }
    return false;
}

void solve() {
    cin >> q >> d;
    while (q--) {
        ll x; cin >> x;
        vector<int> v;
        if (d == 1) {
            cout << "YES\n";
        } else {
            ll y = x;
            while (x) {
                v.push_back(x % 10);
                x = x / 10;
            }
            int f = 0;
            if (judge(y)) {
                cout << "YES\n";
            } else {
                ll base = 1;
                f = 0;
                for (int i = 0; i < v.size(); i++) {
                    for (int j = 1; j <= 9; j++) {
                        ll sum = 1ll * j * d * base;
                        ll cnt = y - sum;
                        if (cnt >= 0) {
                            if (cnt == 0 || judge(cnt)) {
                                f = 1;
                                break;
                            }
                        } else {
                            break;
                        }

                    }
                    if (f) break;
                    base = base * 10;
                }
                if (f) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }

    }
}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}