#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 7;

ll fn[N];

int t, n, m;


int main() {
    fn[1] = 1, fn[2] = 2;
    ll mod = 787654321;

    for (int i = 3; i < N; i++) {
        fn[i] = (fn[i - 1]  + fn[i - 2] ) % mod;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if (x == 1) {
                ans = (ans  + fn[i] ) % mod;
            } 
        }
        ll ans1 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if (x == 1) {
                ans1 = (ans1  + fn[i] ) % mod;
            }
        }
        ll ans2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if (x == 1) {
                ans2 = (ans2 + fn[i] ) % mod;
            }
        }
        ans = ((ans % mod * ans1 % mod)%mod - ans2  + mod) % mod;
        for (int i = 1; i < N; i++) {
            if (fn[i] == ans) {
                printf("%d\n", i);
                break;
            }
        }
        
    }
}