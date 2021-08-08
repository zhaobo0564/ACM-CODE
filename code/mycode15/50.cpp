#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, a[N], m, b[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &a[i]);
    }
    while (m--) {
        int f = 0;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
            if (a[i]) continue;
            if (i == 1) {
                if (a[i + 1] == 1) {
                    b[i] = 1;
                    f = 1;
                }
            } else if (i == n) {
                if (a[i - 1] == 1) {
                    b[i] = 1;
                    f = 1;
                }
            } else {
                if (a[i - 1] == 1 && a[i + 1] == 1) {

                } else if (a[i - 1] == 1) {
                    b[i] = 1;
                    f = 1;
                } else if (a[i + 1] == 1) {
                    b[i] = 1;
                    f = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            a[i] = b[i];
        }
        if (f == 0) break;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] ;
    }
    cout << endl;
}

int main() {
   // ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}