#include<bits/stdc++.h>
const int N = 1e5 + 7;
using namespace std;
typedef long long ll;

ll n, l, r, a[N];

ll sum[2][2], fn[40];
const ll mod = 1e9 + 7;

int main() {
    fn[0] = 1;
    for (int i = 1; i <= 30; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    ios::sync_with_stdio(0);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];
    }

    if (l % 2) l++;
    if (r % 2) r--;
    if (l > r) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= 30; i++) {
        memset(sum, 0, sizeof(sum));
        sum[0][0]++;
        for (int j = 1; j <= n; j++) {
            if ((a[j] & (1 << i))) { // 1
                
                if (j % 2) {
                    if (j >= l) {
                        ans = (ans + sum[1][0] * fn[i] % mod) % mod;
                    }
                } else {
                    if (j >= l) {
                        ans = (ans + sum[0][0] * fn[i] % mod) % mod;
                    }
                    
                }
            } else {
            
                if (j % 2) {
                    if (j >= l) {
                        ans = (ans + sum[1][1] * fn[i] % mod) % mod;
                    }
                    
                } else {
                    if (j >= l) {
                       ans = (ans + sum[0][1] * fn[i] % mod) % mod; 
                    }
                }
            }
            if (j >= l) {
                if ((a[j - l + 1] & (1 << i))) {
                    if ((j - l + 1) % 2) {
                        sum[1][1]++;
                    } else {
                        sum[0][1]++;
                    }
                } else {
                    if ((j - l + 1) % 2) {
                        sum[1][0]++;
                    } else {
                        sum[0][0]++;
                    }
                }
            }

            if (j >= r) {
                if ((a[j - r ] & (1 << i))) {
                    if ((j - r ) % 2) {
                        sum[1][1]--;
                    } else {
                        sum[0][1]--;
                    }
                } else {
                    if ((j - r ) % 2) {
                        sum[1][0]--;
                    } else {
                        sum[0][0]--;
                    }
                }
            }
        }
        //cout << "ans = " << ans << endl;
    }
    cout << ans << endl;
 

     
}