#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n, a[N];

void solve() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int f = 0;
   
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) {

        } else {
            f = 1;
        }
    }
    if (f == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}