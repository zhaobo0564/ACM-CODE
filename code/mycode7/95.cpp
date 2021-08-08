#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

ll a[N], n, k, b[N], c[N], d[N];

ll tree[4 * N], flag[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
}

void push_donw(int node) {
    if (flag[node]) {
        tree[lson] += flag[node];
        tree[rson] += flag[node];
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (qr < ql) return;
    if (ql <= l && qr >= r) {
    //    cout <<"(((\n";
        tree[node] += v;
        flag[node] += v;
        return;
    }
    push_donw(node);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
}

int query(int pos, int l, int r, int node) {
    if (l == r) {
        return tree[node];
    }
    push_donw(node);
    if (pos <= m) return query(pos, l, m, lson);
    return query(pos, m + 1, r, rson);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    build(1, n, 1);
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    int last = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = last; j < b[i]; j++) {
            if (a[j] > a[j - 1]) {

            } else {
                int cnt = a[j - 1] -a[j] + 1;
                a[j] += cnt;
                update(cnt, j, j, 1, n, 1);

            }
        }
        if (a[b[i]] <= a[b[i] - 1]) {
            int cnt = a[b[i] - 1] - a[b[i]] + 1;
           // cout << "cnt " << cnt << endl;
         //   cout << "l = " << last << " r = " << b[i] - 1 << endl;
            update(-cnt, last, b[i] - 1, 1, n, 1);
        }
        last = b[i] + 1;
    }

    for (int j = last; j <= n; j++) {
        if (a[j] > a[j - 1]) {

            } else {
                int cnt = a[j - 1] -a[j] + 1;
                a[j] += cnt;
                update(cnt, j, j, 1, n, 1);

            }
        }
       
    



    for (int i = 1; i <= n; i++) {
        
        c[i] = query(i, 1, n, 1);//cout << c[i] << " ";
    }

    for (int i = 2; i <= n; i++) {
        if (c[i] > c[i - 1]) {

        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] != c[i]) {
            ans++;
        }
    }
    cout << ans << endl;

    

    
}