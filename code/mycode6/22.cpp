#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, a[N];


void solve() {
    cin >> n;
    int one = 0, two = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)one++;
        else two++;
    }
    if (one >= two) {
        cout << one << endl;
        for (int i = 1; i <= one; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    } else {
        if (two % 2 != 0) {
            two--;
        }
        cout << two<< endl;
        for (int i = 1; i <= two; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }



}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}