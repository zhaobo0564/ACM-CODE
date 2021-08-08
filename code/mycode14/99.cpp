#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

ll a[N], n, k, sum[N];
int dp[N][30];

void work(int l, int r) {
    int id = l;
    int ans = l;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll res = sum[mid] - sum[id - 1];
        if (res <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    dp[id][0] = ans + 1;
}




int main() {
   // ios::sync_with_stdio(0);
    int q;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        //work(i, n);
        int pos = upper_bound(sum+i,sum+n+1,sum[i-1]+K) - sum;
        dp[i][0] = pos;
    }
    for (int i = 0; i <= 21; i++) {
        dp[n + 1][i] = n + 1;
    }

    for (int j = 1; j <= 21; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int ans = 0;
        for (int i = 21; i >= 0; i--) {
           // cout << "R = " << dp[l][i] << endl;
            if (dp[l][i] <= r) {
                l = dp[l][i];
                ans += (1 << i);
            }
        }
        if (dp[l][0] <= r) {
            cout << "Chtholly" << endl;
        } else {
           cout << ans + 1 << endl; 
        }
        
    }
}
