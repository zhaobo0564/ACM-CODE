#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

int  block[N], q, n, L[N], R[N];
ll flag[N], a[N], sum[N];

void init() {
    for (int i = 1; i <= n; i++) {
        if (L[block[i]] == 0) {
            L[block[i]] = i;
        } 
        R[block[i]] = max(R[block[i]], i);
        sum[block[i]] += 1ll*a[i];
    }
    
}

void update(int l, int r, int v) {
    if (block[l] == block[r]) {
        for (int i = l; i <= r; i++) {
            a[i] += 1ll*v;
            sum[block[i]] += 1ll*v;
        }
       
    } else {
        for (int i = l; i <= R[block[l]]; i++) {
            a[i] += 1ll*v;
            sum[block[i]] += 1ll * v;
        }
        for (int i = R[block[l]] + 1; i <= L[block[r]] - 1; i = R[block[i]] + 1) {
            flag[block[i]] += 1ll * v;
            
        }
        for (int i = L[block[r]]; i <= r; i++) {
            a[i] += 1ll * v;
            sum[block[i]] += 1ll * v;
        }
    }
    // for (int i = l; i <= r; i++) {
    //     sum[block[i]] += 1ll*v;
    //     a[i] += 1ll*v;
    // }
}

ll query(int l, int r) {
    ll ans = 0;
    if (block[l] == block[r]) {
        
       for (int i = L[block[l]]; i <= R[block[l]]; i++) {
           a[i] += flag[block[i]];
           sum[block[i]] += flag[block[i]];
           
       }
       flag[block[l]] = 0;
       for (int i = l; i <= r; i++) {
           ans += 1ll*a[i];
       }
    } else {
        for (int i = L[block[l]]; i <= R[block[l]]; i++) {
            a[i] += flag[block[i]];
            sum[block[i]] += flag[block[i]];
        }
        flag[block[l]] = 0;
        for (int i = l; i <= R[block[l]]; i++) {
            ans += a[i];
        }
   //     cout << "l = " << l << " R= " << R[block[l]] << endl;
     //   cout <<"ans=" << ans << endl;
        for (int i = R[block[l]] + 1; i <= L[block[r]] - 1; i = R[block[i]] + 1) {
            ans += sum[block[i]];
           // cout << "L = " << L[block[i]] << " r = " << R[block[i]] << endl;
           // cout << sum[block[i]] << endl;
            ans += flag[block[i]] * 1ll* (R[block[i]] - L[block[i]] + 1);
        }
       // cout << "ans = " << ans << " l = "<< R[block[l]] + 1 << " r = " << L[block[r]] - 1 << endl;  
        for (int i = L[block[r]]; i <= R[block[r]]; i++) {
            a[i] += flag[block[i]];
            sum[block[i]] += flag[block[i]];
        }
        flag[block[r]] = 0;
        for (int i = L[block[r]]; i <= r; i++) {
            ans += a[i];
        }
        
    }

    return ans;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        block[i] = i / b;
    }
    init();
    while (q--) {
        char op;
        cin >> op;
        int l, r;
        scanf("%d %d", &l, &r);
        if (op == 'Q') {
            printf("%lld\n", query(l, r));
        } else {
            int v; scanf("%d", &v);
            update(l, r, v);
        }
    }
}