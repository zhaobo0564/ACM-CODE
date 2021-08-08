#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll a[N], n, block[N], sum[N], flag[N];
int L[N], R[N];

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

ll query(int l) {
   // cout << "L = " << L[block[l]] << " R = " << R[block[l]] << endl;
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        a[i] += flag[block[l]];
    }
    flag[block[l]] = 0;
   
    return a[l];
}

void update(ll v, int l, int r) {
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        if (i >= l && i <= r)
            a[i] += v;
    }
    if (block[l] != block[r])
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            if (i >= l && i <= r)
                a[i] += v;
        }
    for (int i = block[l] + 1; i <= block[r] - 1; i++) {
      //  cout << "pos " << i << endl;
        flag[i] += v;
    }

}

int main() {
    cin >> n;
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        block[i] = i / b;
    }
    build();
    while(n--) {
        int op, l, r, c;
        scanf("%d %d %d %d", &op, &l, &r, &c);
        if (op == 0) {
            update(c, l, r);
        } else {
            printf("%lld\n", query(r));
        }
    }

}   