#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, a[N], k;
set<int> v;
void solve() {
    cin >> n >> k;
    
    v.clear();
    for (int i = 1; i <= n; i++) {
       cin >> a[i];
       v.insert(a[i]);
    }

    if (k == 1) {
        if (v.size() <= k) {
            cout << 1 << endl;
        } else {
            if (a[1] == 0 && a[n] != 0) {
                cout << -1 << endl;
            } else {
                if (a[1] == 0 && a[n] == 0) {
                    cout << 1 << endl;
                } else if (a[1] == a[n]) {
                   cout << 1 << endl;
                    
                } else {
                    cout << -1 << endl;
                }
            }
        }
    } else {
        if (v.size() <= k) {
            cout << 1 << endl;
        } else {
            int cnt = v.size();
            cnt -= k;
            int ans = 1;
            k--;
            ans += cnt / k;
            if (cnt % k) ans++;
            cout << ans << endl;
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