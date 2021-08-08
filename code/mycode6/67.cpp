#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

int n, m;

void solve() {
    cin >> n >> m;
    int f = 0;
    for (int i = 1; i <=  n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(c == b) {
            f = 1;
        }
    }
    if (m % 2) {
        cout << "NO\n";
    }else if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}