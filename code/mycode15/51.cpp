#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], n;

void print(int x, int y, int z) {

    cout << x << " "<< y << " " << z << endl;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << 3 * n << endl;
    for (int i = 1; i <= n; i += 2) {
       print(2, i, i + 1);
       print(1, i, i + 1);
       print(2, i, i + 1);
       print(1, i, i + 1);
       print(2, i, i + 1);
       print(1, i, i + 1);
    }
   

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}