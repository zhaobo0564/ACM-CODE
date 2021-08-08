#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int mp[N][N], cnt[N][N], n, m, q, line[N];

bool judge() {
    for (int i = 1; i <= n; i++) {
        if (line[i]) return false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] || cnt[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (y <= m) {
            mp[x][y] = 1;
        } else {
            cnt[x][y - m] = 1;
        }
    }
    int ans = 0;
    while (1) {
        if (judge()) {
            break;
        }
        int f = 0;
        for (int i = n; i; i--) {
            if (line[i]) {
                f++;
            }
        }
        if (f == n) {
            break;
        }
        int ok = 0;
        for (int i = n; i; i--) {
            if (line[i]) {
                if (i == n) {
                    line[i] = 0;
                } else if (line[i + 1] == 0) {
                    line[i + 1] = line[i];
                    line[i] = 0;
                }
                
            }
        }
        for (int i = n; i; i--) {
            for (int j = m; j; j--) {
                if (mp[i][j]) {
                    if (j == m) {
                        if (line[i] == 0) {
                            line[i] = 1;
                            mp[i][j] = 0;
                        }
                    } else {
                        if (mp[i][j + 1] == 0) {
                            mp[i][j + 1] = 1;
                            mp[i][j] = 0;
                        }
                    }
                }
            }
        }
        for (int i = n; i; i--) {
            for (int j = 1; j <= m; j++) {
                if (cnt[i][j]) {
                    if (j == 1) {
                        if (line[i] == 0) {
                            line[i] = 1;
                            cnt[i][j] = 0;
                        }
                    } else {
                        if (cnt[i][j - 1] == 0) {
                            cnt[i][j - 1] = 1;
                            cnt[i][j] = 0;
                        } 
                    }
                }
            }
        }
        ans++;
    }
    for (int i = 1; i <= n; i++) {
        if (line[i]) ans++;
        for (int j = 1; j <= m; j++) {
            if (mp[i][j]) ans++;
            if (cnt[i][j]) ans++;
        }
    }
    printf("%d\n", ans);
    
}

// 500 500 16
// 1 1
// 1 2
// 1 999
// 1 1000
// 2 1
// 2 2
// 2 999
// 2 1000
// 3 1 
// 3 2
// 3 999
// 3 1000
// 499 500
// 499 501
// 499 999
// 499 1000