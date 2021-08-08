#include<bits/stdc++.h>
using namespace std;
const int N = 207;
typedef long long ll;
const ll mod = 998244353;
int  A[N][N], B[N][N], n;
bitset<N> a[N];

int gauss()
{
    int r,c;
    for(r=1,c=1;c<=n;c++) {
        // 找主元
        int t = r;
        for(int i=r+1;i<=n;i++)
            if(a[i][c])
                t=i;
        if(!a[t][c])continue;//不保证唯一解--不一定有主元
        // 交换主元行至r行
        swap(a[t], a[r]);
        // 用第r行的a[r][j]消第i行的a[i][j] 前提是第i行的最左边是1(有主元)
        for(int i=r+1;i<=n;i++) {
            if (a[i][c]) {
                a[i] ^= a[r];
            }
        }
        r++;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) f = 1;
        }
        if (f == 0 && a[i][n + 1] == 0) {
        
            res = res * 2 % mod;              // 找自由变元的个数
        } else if (f == 0 && a[i][n + 1]) {
            return 0;
        }
    }
   // cout << "res = " << res << endl;
    return res; // 解的个数。
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                a[j][k] = A[j][k];
            }
            if (B[j][i]) {
                a[j][j] = a[j][j] ^ B[j][i];
            }
        }

        ans = ans * gauss() % mod;

    }
    cout << ans << endl;

}