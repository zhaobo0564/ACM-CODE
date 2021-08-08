#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

int n, a[N];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve() {
    int k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    if (k == 0) {
        print();
        return;
    }
    int cnt = 0;
    for (int i = 2; i <= n; i += 2) {
        if (i + 1 > n) break;
        swap(a[i], a[i + 1]);
        cnt++;
        if (cnt == k) break;
    }
    if (cnt == k) {
        print();
    } else {
        cout << -1 << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}