#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;

int n, a[N];

#define  m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1  

struct hjt{
    int sum, l, r;
}tree[150 * N];



struct segement{
    int tr[4 * N];
    void build(int l, int r, int node) {
        if (l == r) {
            tr[node] = a[l];
            return;
        }
        build(l, m, lson);
        build(m + 1, r, rson);
        tr[node] = tr[lson] & tr[rson];
    }

    int query(int ql, int qr, int l, int r, int node) {
        if (ql <= l && qr >= r) {
            return tr[node];
        }
        int ans = INT_MAX;
        if (ql <= m) ans = ans & query(ql, qr, l, m, lson);
        if (qr > m) ans = ans & query(ql, qr, m + 1, r, rson);
        return ans;
    }
};


int top = 1, rt[N];

void update(int v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum += v;
        return;
    }
    if (pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

int query(int ql, int qr, int now, int l, int r) {
    if (ql <= l && qr >= r) {
        return tree[now].sum;
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, tree[now].l, l, m);
    if (qr > m) ans += query(ql, qr, tree[now].r, m + 1, r);
    return ans;
}

unordered_map<int, int>vis;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    segement cnt;
    cnt.build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] == 0) {
          //  cout << "i " << i << endl;
            update(1, i, rt[i - 1], rt[i], 1, n);
         //   cout << "ans " << query(3, 3, rt[i], 1, n) << endl;
        } else {
            int temp;
            update(-1, vis[a[i]], rt[i - 1], temp, 1, n);
            update(1, i, temp, rt[i], 1, n);
        }
        vis[a[i]] = i;

        int l = 1, r = i,  ans = -1, base = a[i];
        for (int j = 1; j <= 30; j++) {
            ans = -1;
            l = 1;
            while (l <= r) {
                int cat = cnt.query(m, i, 1, n, 1);
              //  cout << "l " << m << " r " << i << " cat " << cat << endl;
               // cout << "base " << base << endl;
                if (cat < base) {

                    ans = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            r = ans;
            if (ans == -1) continue;
            base = cnt.query(ans, i, 1, n, 1);
          //  cout << "base " << base << " ans " << ans  << " i " << i << endl;
            if (vis[base]) {
                int temp;
                update(-1, vis[base], rt[i], temp, 1, n);
                update(1, ans, temp, rt[i], 1, n);
            } else {
              //  cout << "ans " << query(3, 3, rt[i], 1, n) << endl;
                update(1, ans, rt[i], rt[i], 1, n);
               // cout << "ans " << query(3, 3, rt[i], 1, n) << endl;
            }
            
            
            vis[base] = ans;
        }
    }
    int q; scanf("%d", &q);
    int Ans = 0;
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        l = (Ans ^ l) % n + 1;
        r = (Ans ^ r) % n + 1;
        if (l > r)swap(l, r);
       // cout << "l = " << l << " r = " << r << endl;
         
        printf("%d\n", Ans = query(l, r, rt[r], 1, n));
    }

}