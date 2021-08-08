#include<bits/stdc++.h>
using namespace std;

const int N = 200;

char mp[N][N];
int n, m, l[N], r[N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'W') {
                l[i] = j;
                break;
            }
        }
        for (int j = m; j; j--) {
            if (mp[i][j] == 'W') {
                if (mp[i][j] == 'W') {
                    r[i] = j;
                    break;
                }
            }
        }
    }
    int x = 1, y = 1, ans = 0;
    
    for (int i = 1; i <= n; i++) {
      //  cout << "x = " << x << " y = " << y << endl;
        // 奇数向左偶数向右
        if (i % 2) {
            if (l[i] && l[i] < y) {
                ans += y - l[i];
                y = l[i];
            }

            if (r[i] && r[i] > y) {
                ans += r[i] - y;
                y = r[i];
            }
            


        } else {
            if (r[i] && r[i] > y) {
                ans += r[i] - y;
                y = r[i];
            }
            if (l[i] && l[i] < y) {
                ans += y - l[i];
                y = l[i];
            }
        }
        int f = 0;
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (mp[j][k] == 'W') {
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        x += f;
        ans += f;
    }
    cout << ans << endl;

}