#include <bits/stdc++.h>
using namespace std;

int fn[130007][507];

void solve(int n, int k) {
     for (int i = 1; i <= 2000000; i++) {
        int g = __gcd(i, k);
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (j == k) continue;
            if (__gcd(i, j) == g) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            printf("%d\n", i);
            return;
        }
    }
    puts("-1\n");
}

int main() {
    

    int t; scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        solve(n, k);
       
    }
}

