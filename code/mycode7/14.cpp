#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 +7;
typedef long long ll;


int n;


void solve() {
    cin >> n;
    int x = 0, y = 0, z = 0;

    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            int cnt = i * 7 + j * 5;
            if (n >= cnt) {
                cnt = n - cnt;
                if (cnt % 3 == 0) {
                    x = cnt / 3;
                    y = j;
                    z = i;
                    cout << x << " " << y << " " << z << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}