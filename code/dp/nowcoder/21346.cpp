#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[51][2050];

const ll mod = 1e9 + 7;
int n, m, h, w;
typedef long long ll;

ll odd[20][20], even[20][20];

char mp[60][60];

bool check(int x, int y) {
    int cnt = 0;
    int base = y;
    while (base) {
        if (base & 1) cnt++;
        base = base / 2;
    }
    if (cnt % 2 == 0) return false;

    for (int i = 0; i < m; i++) {
        if (odd[x][i] && even[x][i]) {

        } else if (odd[x][i]) {
            if ((y & (1 << i))) {

            } else {
                return false;
            }
        } else if (even[x][i]) {
            if ((y & (1 << i))) {
                return false;
            }
        }
    }

    return true;
}



int main() {
    cin >> h >> w >> n >> m;
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            odd[i][j] = 1;
            even[i][j] = 1;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '.') {
                odd[i % n][j % m] *= 5;
                odd[i % n][j % m] %= mod;
                even[i % n][j % m] *= 4;
                even[i % n][j % m] %= mod;
            } else if ((mp[i][j] - '0') % 2) {
                even[i % n][j % m] = 0;
            } else {
                odd[i % n][j % m] = 0;
            }
            
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (even[i][j] == 0 && odd[i][j] == 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (!check(i - 1, j)) continue;
            ll sum = 1;
            for (int k = 0; k < m; k++) {
                if (mp[i - 1][k] == '.') {
                    if (j & (1 << k)) {
                        sum = sum * odd[i - 1][k] % mod;
                    } else {
                        sum = sum * even[i - 1][k] % mod;
                    }
                } else if ((mp[i - 1][k] - '0') % 2) {
                    sum = sum * odd[i - 1][k] % mod;
                } else {
                    sum = sum * even[i - 1][k] % mod;
                }
            }
            for (int k = 0; k < (1 << m); k++) {
                dp[i][k ^ j] = (dp[i][k ^ j] + dp[i - 1][k] * sum % mod) % mod;
            
            }
        }
       
    }
     cout << dp[n][(1 << m) - 1] << endl;

   
}