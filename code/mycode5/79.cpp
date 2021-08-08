#include<bits/stdc++.h>
using namespace std;

int n, m, x, y, mp[300][300];

int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    printf("%d %d\n", x, y);
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        printf("%d %d\n", i, y);
    }
    int f = 0;
    for(int i = 1; i <= m; i++) {
        if (i == y) continue;
        if (f == 0) {
            for (int j = n; j; j--) {
                printf("%d %d\n", j, i);
            }
            f = 1;
        } else {
            for (int j = 1; j <= n; j++) {
                printf("%d %d\n", j, i);
            }
            f = 0;
        }
    }
}