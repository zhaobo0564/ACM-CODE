#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
char s[N];

void solve() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int one = 0, two = 0, three = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'S') {
            one++;
        } else if (s[i] == 'P') {
            two++;
        } else {
            three++;
        }

    }
    if (one >= two && one >= three) {
        for (int i = 1; i <= n; i++) {
            cout << "R";
        }
    } else if (two >= one && two >= three) {
        for (int i = 1; i <= n; i++) {
            cout << "S";
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cout << "P";
        }
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