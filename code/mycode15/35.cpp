#include<bits/stdc++.h>
using namespace std;

const int N = 107;

int mp[N][N], n, k, temp[N][N];

int get_cnt(int x, int y) {
    int ans = 0;
    if (mp[x - 1][y - 1]) {
        ans++;
    }
    if (mp[x - 1][y]) {
        ans++;
    }
    if (mp[x - 1][y + 1]) {
        ans++;
    }
    if (mp[x][y - 1]) {
        ans++;
    }
    if (mp[x][y + 1]) {
        ans++;
    }
    if (mp[x + 1][y - 1]) {
        ans++;
    }
    if (mp[x + 1][y]) {
        ans++;
    }
    if (mp[x + 1][y + 1]) {
        ans++;
    }
    return ans;
}

int fi[N][N];

bool work() {
    for (int i = 1; i <= n; i++) {
        mp[i][0] = mp[i][n];
        mp[0][i] = mp[n][i];
        mp[i][n + 1] = mp[i][1];
        mp[n + 1][i] = mp[1][i];
    }
    mp[0][0] = mp[n][n];
    mp[0][n + 1] = mp[n][1];
    mp[n + 1][n + 1] = mp[1][1];
    mp[n + 1][0] = mp[1][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int ans = get_cnt(i, j);
            if (mp[i][j] == 0) {
                if (ans == 3) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = mp[i][j];
                }
            } else {
                if (ans > 3 || ans < 2) {
                    temp[i][j] = 0;
                } else {
                    temp[i][j] = mp[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = temp[i][j];
       
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] != fi[i][j]) {
                return false;
            }
        }
    }
    return true;


}

void solve() {

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mp[i][j]);
            fi[i][j] = mp[i][j];
        
        }
    }
    for (int i = 1; i <= k; i++) {
        if (work()) {
            printf("YES\n");
            printf("%d\n", i);
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}