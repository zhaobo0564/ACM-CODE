#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, t, a[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int pos = n;
        for (int i = n - 1; i; i--) {
            if (a[i + 1] <= a[i] ) {
                pos = i;
            } else {
                break;
            }
        }
        for (int i = pos - 1; i; i--) {
            if (a[i + 1] >= a[i]) {
                pos = i;
            } else {
                break;
            }
        }
        printf("%d\n", pos - 1);
    }
}