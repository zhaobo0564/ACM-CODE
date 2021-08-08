#include<bits/stdc++.h>
using namespace std;

int t, n, b[1007];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            if (100 % x == 0) {
                b[i] = (100 / x - 1) * y;
            } else {
                b[i] = ((100 / x) ) * y;
            }
        }
        sort(b + 1, b + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == b[1]) {
                cnt++;
            } else {
                break;
            }
        }
        double ans = (double)cnt / double(n);
        ans = ans * 0.5;
        printf("%.7lf\n", 1 - ans);

    }
}