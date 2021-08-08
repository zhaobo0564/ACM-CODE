#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll n, a[N], b[N]; 

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);
    ll ansa = 0, ansb = 0;
    int i = 1, j = 1;
    while (1) {
        if (i <= n && j <= n && a[i] >= b[j]) {
            ansa += a[i];
            i++;
        } else if (i <= n && j <= n) {
            j++;
        } else if (i <= n) {
            ansa+= a[i];
            i++;
        } else if (j <= n) {
            j++;
        }
        if (i > n && j > n) break;
        if (i <= n && j <= n && a[i] <= b[j]) {
            ansb += b[j];
            j++;
        } else if (i <= n && j <= n) {
            i++;
        } else if (i <= n) {
            i++;
        } else if (j <= n) {
            ansb += b[j];
            j++;
        }
        if (i > n && j > n) break;
    }
    cout << ansa - ansb << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
}