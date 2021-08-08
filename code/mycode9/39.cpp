#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

ll a[N], sum[N];

int n, flag[N], block[N], L[N], R[N];

void build() {
    for (int i = 1; i <= n; i++) {
        sum[block[i]] += a[i];
        L[block[i]] = n + 1;
        R[block[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }

}

void update(int l, int r) {
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            a[i] = sqrt(a[i]);
        }
    }
    sum[block[l]] = 0;
    ll maxn = 0;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        sum[block[l]] += a[i];
        maxn = max(maxn, a[i]);
    }
    flag[block[l]] = maxn;
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r) {
                a[i] = sqrt(a[i]);
            }
        }
        sum[block[r]] = 0;
        maxn = 0;
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            sum[block[r]] += a[i];
            maxn = max(maxn, a[i]);
        }
        flag[block[r]] = maxn;
        for (int i = block[l] + 1; i < block[r]; i++) {
            if (flag[i] != 1) {
                for (int j = L[i]; j <= R[i]; j++) {
                    a[j] = sqrt(a[j]);
                }
                maxn = 0;
                sum[i] = 0;
                for (int j = L[i]; j <= R[i]; j++) {
                    maxn = max(maxn, a[j]);
                    sum[i] += a[j];
                }
                flag[i] = maxn;
            }
        }
    }
}

ll query(int l, int r) {
    ll ans = 0;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            ans += a[i];
        }
    }
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r) {
                ans += a[i];
            }
        }
        for (int i = block[l] + 1; i < block[r]; i++) {
            ans += sum[i];
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        block[i] = i / b;
    }
    build();
    int q = n;
    while (q--) {
        int op, l, r, c;
        scanf("%d %d %d %d", &op, &l, &r, &c);
        if (op == 0) {
            update(l, r);
        } else {
            printf("%lld\n", query(l, r));
        }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << a[i] << " " ;
        // }
        // cout << endl;
    }
    

}