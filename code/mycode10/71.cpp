#include<bits/stdc++.h>

using namespace std;

const int N = 160;

char mp[N][N];

int n, m;



int main() {
    scanf("%d %d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          scanf(" %c", &mp[i][j]);

        }
    }
    int nowx, nowy;
    int ans = 0, x = 1, y = 1;
    for (int i = 1; i < n; i++) {
        
        if (i % 2) {
            int ex = 0;
             for (int j = 1; j <= m; j++) {
                if (mp[i][j] == 'W') {
                    ex = max(ex, j);
                }
                if (mp[i + 1][j] == 'W') {
                    ex = max(ex, j);
                }
            }
            if (ex == 0) continue;
            nowx = x + 1, nowy = ex;
        } else {
            int ex = m + 1;
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == 'W') {
                    ex = min(ex, j);
                }
                if (mp[i + 1][j] == 'W') {
                    ex = min(ex, j);
                }
            }
            if (ex == m + 1) continue;
            nowx = x + 1, nowy = ex;

        }
        //cout << "x = " << nowx << " y = " << nowy << endl;
        ans += abs(nowx - x) + abs(nowy - y);
        x = nowx, y = nowy;
    }
    int f = 0;
    if (n % 2 == 0) {
        for (int i = 1; i <= m; i++) {
            if (mp[n][i] == 'W') {
                f = 1;
                ans += abs(i - y);
                break;
            }
        }
    } else {
        for (int i = m; i; i--) {
            if (mp[n][i] == 'W') {
                f = 1;
                ans += abs(i - y);
                break;
            }
        }
    }
    if (f == 0) {
        if (mp[nowx][nowy] != 'W') {
            ans--;
        }
    }
    cout << ans << endl;


}