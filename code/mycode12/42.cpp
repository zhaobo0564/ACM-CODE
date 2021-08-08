#include<bits/stdc++.h>
using namespace std;

const int N = 40;

int a[N][N], b[N], n, s[N], e[N];

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
        for(int i=c;i<=n+1;i++)swap(a[t][i],a[r][i]);
        // 用第r行的a[r][j]消第i行的a[i][j] 前提是第i行的最左边是1(有主元)
        for(int i=r+1;i<=n;i++)
            for(int j=n+1;j>=c;j--)
            //等价于if(a[i][c]) a[i][j]^=a[r][j]
                a[i][j] ^= a[i][c] & a[r][j];
        //不能写a[i][j] ^= a[i][r] & a[r][j];
        //是因为可能存在中间无主元的情况 此时r不++了 c还在循环中++ 导致r!=c
        r++;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) f = 1;
        }
        if (f == 0 && a[i][n + 1] == 0) {
            res = res * 2;              // 找自由变元的个数
        } else if (f == 0 && a[i][n + 1]) {
            return -1;
        }
    }
    return res; // 解的个数。
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    cout << gauss() << endl;
}