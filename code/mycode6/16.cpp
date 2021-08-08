#include<bits/stdc++.h>
using namespace std;


const int N = 2e5 + 7;

typedef long long ll;

int n, a[1000];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i; i--) {
        cout << a[i] << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}