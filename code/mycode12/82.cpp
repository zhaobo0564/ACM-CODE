#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, k;

void solve() {
    cin >> n >> k;
    if (n == 4) {
        cout << 2 << " " << 1 << " " << 1 << endl;
        return ;
    }
    if (n % 2) {
        cout << n / 2 << " " << n / 2 << " " << 1 << endl;
    } else {
       int cnt = n / 2;
       if (cnt % 2) {
           cout << cnt / 2 + cnt / 2 << " " << cnt / 2 + cnt / 2 << " " << 2 << endl;
       } else {
           cout << cnt << " " << cnt / 2  << " " << cnt / 2 << endl; 
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