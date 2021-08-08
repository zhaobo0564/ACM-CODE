#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, k, a[N];

void solve() {
    cin >> n >> k;
    int cnt = n - k;
    if (cnt == 0) {
        for (int i = 1; i <= k; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    if (n % k == 0) {
        for (int i = 1; i <= k; i++) {
            cout << n / k << " ";
        }
        cout << endl;
    } else {
        if (n % 2 == 0) {
            
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}