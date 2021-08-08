#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(l, r) for (int i = l; i <= r; i++)
const int N = 2e5 + 7;
int n, a[N], d;

void solve() {
    cin >> n >> d;
    int ans = 0;
    rep(1, n) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    sort(a + 1, a + n + 1);
    if (a[1] + a[2] <= d || ans <= d) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}


int main() {
    int t; cin >> t;
    while (t--) {
       solve();
    }

}