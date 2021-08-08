#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

int n, a[N];

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
     
    }
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            cout << a[n - i + 1] << " ";
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            cout << -a[n - i + 1] <<  " ";
        }
        cout << endl;
    } else {
        cout << 

    }



}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}