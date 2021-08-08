#include<bits/stdc++.h>
using namespace std;

const int N = 207;

int a[N], b[N], n, m, vis[N];


int main() {
    while (~scanf("%d", &n)) {
        int f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > 0) {
                f = 1;
            }
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            vis[b[i]] = 1;
        }
        if (f == 0) {
            puts("0.00");
        }else if (m == n) {

            puts("inf");
        } else {
            double cnt = (double) m / (double) n;
            double ans = 0.0;
            for (int i = 1; i <= n; i++) {
                ans += (double) a[i];
            }
            ans = ans / (double) n;
            double ANS = 0.0;
            double base = 1.0;
            for (int i = 1; i <= 10000; i++) {
                ANS += ans * base;
                base = base * cnt;
            }
            printf("%.2f\n", ANS);
        }
    }
}