#include <bits/stdc++.h>

using namespace std;
const int N = 4007;

char mp[N][N];

int d[N][N], dl[N][N], dr[N][N];

int lmin[N][N], rmin[N][N];

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           // scanf(" %c", &mp[i][j]);
           cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'X') {
                d[i][j] = d[i - 1][j] + 1;
                dl[i][j] = dl[i - 1][j - 1] + 1;
                dr[i][j] = dr[i- 1][j + 1] + 1;
            } 
        }
    }


   // cout << dl[5][5] << endl;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         lmin[i][j] = min(d[i][j], dr[i][j]);
    //         rmin[i][j] = min(d[i][j], dl[i][j]);
    //     }
    // }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           // if (mp[i][j] != 'X') continue;
           int  cnt =  min(d[i][j], dr[i][j]);
            if (cnt % 2 == 0)cnt--;
            for (int k = cnt; k > ans; k-= 2) {
                if (min(d[i][j + k -1], dl[i][j + k - 1]) >= k ) {
                    ans = k;
                    break;
                }
            }
        }
    }
   // if (ans == 1) ans = 0;
    cout << ans << endl;

}
