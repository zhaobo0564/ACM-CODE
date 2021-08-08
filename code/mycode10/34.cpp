#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    if (n == 1 || n == 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
       if (n % 2) {
           cout << n - 1 << " ";
           for (int i = 1; i < n; i++) {
               cout << i << " ";
           }
           cout << endl;
           cout << 1 << " " << n << endl;
       } else {
           cout << n - 1 << " ";
           for (int i = 1; i <= n; i++) {
               if (i == n / 2) continue;
               cout << i << " ";
           }
           cout <<  endl;
           cout << 1 << " " << n / 2 << endl;
       }
    }

}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;// cin >> t;
    while (t--) {
        solve();
    }
}