#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
typedef long long ll;

ll n, a[N], sum[N], flag[N];

ll block[N], L[N], R[N];

void build() {
    for (int i = 1; i <= n; i++) {
        sum[block[i]] += a[i];
        L[block[i]] = n + 1;
        R[block[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        L[block[i]] = min(L[block[i]], 1ll*i);
        R[block[i]] = max(R[block[i]], 1ll*i);
    }
}

void update(int l , int r, ll v) {
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            a[i] += v;
            sum[block[l]] += v;
        }
    }
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r) {
                a[i] += v;
                sum[block[r]] += v;
            }
        }
        for (int i = block[l] + 1; i < block[r]; i++) {
            flag[i] += v;
        }
    }
}

ll query(int l, int r) {
    ll ans = 0;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r) {
            ans += a[i] + flag[block[l]];
        }
    }
    if (block[l] != block[r]) {
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r) {
                ans += a[i] + flag[block[r]];
            }
        }

        for (int i = block[l] + 1; i < block[r]; i++) {
            ans += sum[i] + flag[i] * 1ll*(R[i] - L[i] + 1);
        }
    }
    return ans;
}



int main() {
    scanf("%lld", &n);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
        block[i] = i / b;
    }
    build();
    int q = n;
    while (q--) {
        ll op, l, r, c;
        scanf("%lld %lld %lld %lld", &op, &l, &r, &c);
        if (op == 0) {
            update(l, r, c);
        } else {
            c++;
            printf("%lld\n", query(l, r) % c);
        }
    }
}