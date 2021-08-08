#include<bits/stdc++.h>
using namespace std;

int t, n, m;

char mp[300][300];

int work(int x, int y) {
    int ans = 0;
    while (1) {
        if (mp[x][y] == 'R') {
            y++;
        } else if (mp[x][y] == 'D') {
            x++;
        } else{
            break;
        }
        if (x > n) {
            x--;
            mp[x][y] = 'R';
            ans++;
        }
        if (y > m) {
            y--;
            mp[x][y] = 'D';
            ans++;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf(" %c", &mp[i][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += work(i, j);
            }
        }
        printf("%d\n", ans);

    }
}