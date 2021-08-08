#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], b[N], n, y;

int dp[500], fn[500];

int main() {
    
    cin >> n >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dp[100] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = -y; j <= y; j++) {
            if (dp[j + 100] == 1){
                fn[(a[i] + b[i] + j) % y + 100] = 1;
                fn[(a[i] - b[i] + j ) % y+ 100] = 1;
                fn[(j + a[i]) % y + 100] = 1;
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int j = -y; j <= y; j++) {
            dp[(a[i] + b[i] + j) % y + 100] = fn[(a[i] + b[i] + j) % y + 100];
            dp[(a[i] - b[i] + j ) % y + 100] = fn[(a[i] - b[i] + j ) % y+ 100];
        }
        memset(fn, 0, sizeof(fn));
    }
    int ans = -1999999;
    for (int i = -y; i <= y; i++) {
        if (dp[i + 100]) {
           // cout << i << endl;
            ans = max(ans, i );
        }
    }
    cout << ans << endl;

}