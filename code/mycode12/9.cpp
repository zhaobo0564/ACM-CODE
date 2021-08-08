#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], n, q;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    int zero = 0, one = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            one++;
        } else {
            zero++;
        }
    }
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            if (a[x] == 1) {
                a[x] = 0;
                one--;
                zero++;
            } else {
                a[x] = 1;
                one++;
                zero--;
            }
        } else {
            if (x <= one) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}