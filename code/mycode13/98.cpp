#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, m, dp[N + 100][10];

void work(int x, int id) {
    dp[x][id] = 2;
    int cnt = 0;
    ll res[11];
    ll cn[11];
    for (int i = 0; i <= 9; i++) {
        res[i] = -1;
    }
    res[0] = res[1] = 1;
    for (int i = x + 1; i < N; i++) {
      //  cout << "i = " << i << endl;
        for (int j = 0; j <= 9; j++) {
            cn[j] = -1;
        }
        for (int j = 0; j < 9; j++) {
            if (res[j] >= 0) {
                cn[(j + 1)] = res[j];
            }
        }
        if (res[9] >= 0) {
            if (cn[1] == -1) {
                cn[1] = res[9];
            } else {  
                cn[1] += res[9];
                cn[1] %= mod;
            }
            if (cn[0] == -1) {
                cn[0] = res[9];
            } else {
                cn[0] += res[9];
                cn[0] %= mod;
            }
        }
     
        for (int j = 0; j <= 9; j++) {
            if (cn[j] >= 0) {
                dp[i][id] += cn[j];
                dp[i][id] %= mod;
            }
            res[j] = cn[j];
        }
        
    }
}

void init() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j < 10 - i; j++) {
            dp[j][i] = 1;
        }
        work(10 - i, i);
    }
   // work(0, 1);
}

void solve() {
    cin >> n >> m;
    ll ans = 0;
    while (n) {
        ans += dp[m][n % 10];
        ans %= mod;
        n = n / 10;
    }
    cout << ans << endl;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}