#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5007;

ll a[N], b[N];

ll sum[N][N], su[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        su[i] = su[i - 1] + a[i] * b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = a[i] * b[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j; j--) {
            sum[i][j] += sum[i - 1][j + 1] ;
        }
    }
    ll ans = su[n], an = su[n];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int len = j - i;
            ll cat = sum[i + len][i] - sum[i - 1][j + 1];
            //cout << "l = " << i << " r = " << j << " cat " << cat << endl;
            ll res = su[j] - su[i - 1];
            res = an - res + cat;
            ans = max(ans, res);
        }
    }
    printf("%lld\n", ans);


    

    
    
}