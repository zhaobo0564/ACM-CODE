#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;
int n, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int f = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                f = 1;
            } else {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << n << endl;
        } else {
            cout << "1" << endl;
        }

    }
}