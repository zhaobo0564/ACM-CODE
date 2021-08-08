#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll fn[N], n, t;
const ll mod = 1e9 + 7;

string s[N];

int main() {
   
    ios::sync_with_stdio(0);
    fn[1] = 1, fn[2] = 2;
    for (int i = 3; i < N; i++) {
        fn[i] = fn[i - 1] + fn[i - 2];
        fn[i] %= mod;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        ll ans = 1;
        int cnt = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i] == s[i - 1]) {
                if (cnt != 1) {
                    ans = ans * fn[cnt];
                    ans %= mod;
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = ans * fn[cnt];
        ans %= mod;
        printf("%lld\n", ans);
    }   
}