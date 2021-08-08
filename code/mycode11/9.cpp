#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, fn[61];

int main() {
    cin >> t;
    fn[0] = 1;
    for (int i = 1; i <= 60; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    while (t--) {
        ll n; 
        cin >> n;
        int f = 0;
        for (int i = 2; i <= 15; i++) {
            if (n % (fn[i] - 1) == 0) {
                f = 1;
                break;
            }
        }
        if (f) {
            puts("YE5");
        } else {
            puts("N0");
        }
    }
}