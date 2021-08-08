#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int n;
typedef long long ll;
const ll mod = 998244353;
ll dp[5000007];
char s[5000007];
ll h[5000007], p[5000007];

int get(int l, int r) {
    return (h[r] - (h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    int lt = strlen(s + 1);
    p[0] = 1;
    for (int i = 1; i <= lt; i++) {
        h[i] = (h[i - 1] *27  + s[i]) % mod;
        p[i] = p[i - 1] * 27 % mod;
    }
    
   // cout << get(1, lt) << endl;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        int x = strlen(s + 1);
        int base = 0;
        for (int i = 1; i <= x; i++) {
            base = (1ll*base * 27  + s[i]) % mod;
        }
        for (int j = lt - x + 1; j; --j) {
            int ha = get(j, j + x - 1);
            if (ha == base) {
                dp[j + x - 1] += dp[j - 1];
            }
        }
    }
    printf("%lld\n", dp[lt]);
    

}