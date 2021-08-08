#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

int a[N], n, k, q, sum[N], lr[N];

int main() {
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int cnt = 1;
    sum[1] = 1;
    a[0] = 0;

    int pos = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            lr[i] = i - 1;
            pos = i - 1;
        } else {
            lr[i] = pos;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            sum[i] = cnt;
        } else {
            sum[i] = ++cnt;
        }
    }

   

    

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        int res = sum[r] - sum[lr[l]];
        //cout << res << endl;
        if (res >= k) {
            puts("Yes");
        } else {
            puts("No");
        }
        

    }


}