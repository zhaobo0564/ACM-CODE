#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2007;

char mp[N][N];

const ll mod = 1e9 + 7;


int n, m;

ll fn[N * N];



int main() {
    fn[0] = 1;
    for (int i = 1; i < N * N; i++) {
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }
    ios::sync_with_stdio(0);
    cin >> n >> m;
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '.') total++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.') {
                ans = ans + fn[total - 1];
                ans %= mod;
                ll f = 0;
                if (mp[i - 1][j] == '.') {
                  
                    f++;
                }
                if (mp[i + 1][j] == '.') {
                
                    f++;
                }
                if (mp[i][j + 1] == '.') {
                  
                    f++;
                }
                if (mp[i][j - 1] == '.') {
                
                    f++;
                }
               

               ans = (ans % mod + ((fn[f] - 1 + mod) % mod * fn[total - f - 1] % mod) % mod) % mod;
            
            }
        }
    }
    cout << ans << endl;
    
    
}