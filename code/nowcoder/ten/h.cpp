#include<bits/stdc++.h>
using namespace std;

int mp[400][400];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n == 2) {
            puts("10");
            puts("00");
            continue;
        } else if (n % 2 == 0) {
            for (int i = 1; i <= n; i++ ) {
                for (int j = 1; j <= n; j++) {
                    if (i % 2) {
                        if (j % 2) {
                            mp[i][j] = 1;
                        } else {
                            mp[i][j] = 0;
                        }
                    } else {
                        mp[i][j] = 0;
                    }
                }
            }
            for (int i = 1; i <= n; i += 4) {
                mp[i + 3][n] = 1;
            }
        } else {
            for (int i = 1; i <= n; i++ ) {
                for (int j = 1; j <= n; j++) {
                    if (i % 2) {
                        if (j % 2) {
                            mp[i][j] = 1;
                        } else {
                            mp[i][j] = 0;
                        }
                    } else {
                        mp[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d", mp[i][j]);
            }
            puts("");
        }
    }
}