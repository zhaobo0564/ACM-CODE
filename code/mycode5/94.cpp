#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
const int N = 2e5 + 7;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        if (n % 2) {
            if (k <= n) {
                if (k % 2) {
                    cout << "0\n";
                } else {
                    cout << "1\n";
                }
            } else {
                cout << k - n << endl;
            }
        } else {
            if (k <= n) {
                if (k % 2 == 0) {
                    cout << 0 << endl;
                } else {
                    cout << 1 << endl;
                }
            } else {
                cout << k - n << endl;
            }
        }
    }
}