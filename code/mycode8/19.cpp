#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N], n, q;

int main() {
    cin >> n >> q;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin  >> a[i];
        sum ^= a[i];
    }

    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int cnt = a[x] ^ y;
        a[x] = y;
        sum = sum ^ cnt;
        if (sum == 0) {
            puts("Li");
        } else {
            puts("Kan");
        }
    }
}