#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y;

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> x >> y;

        if (x == 0 || x == 1) {
            puts("-1");
        }  else {
            if (x > y) {
                if (y >= 1) {
                    puts("0");
                } else {
                    puts("-1");
                }
            } else {
                __int128 base = 1;
                __int128 cnt = x;
                int ans = 0;
                for (int i = 1; i <= 100; i++) {
                    base = base * cnt;
                    if (base <= y) {
                        ans = i;
                    } else {
                        break;
                    }
                }
                cout << ans << endl;
            }
        }
    }
}