#include<bits/stdc++.h>
using namespace std;

const int N = 40;

int a[N][N], b[N], n, s[N], e[N];

int gauss() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (a[j][i] > 0) {
                for (int k = 1; k <= n; k++) {
                    swap(a[i][k], a[j][k]);
                }
            }
        }
        if (!a[i][i]) continue;
        
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                for (int k = 1; k <= n; k++) {
                    if (i != j && a[k][j]) {
                        a[k][j] ^= a[i][j];
                    }
                }
                break;
            }
        }

    }
    return 0;
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &e[i]);
            b[i] = (e[i] ^ s[i]);
        }
        int x, y;
        while (scanf("%d %d", &x, &y) && x) {
            a[y][x] = 1;
        }
        int ans = gauss();
        if (ans < 0) {
            puts("Oh,it's impossible~!!");
        } else {
            cout << (1 << ans) << endl;
        }



    }
}