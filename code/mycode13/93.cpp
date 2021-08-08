#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;

struct segment {
    int l, r;

    segment() {
        this->l = -10;
        this->r = -10;
    }
} tree[40 * N];

#define m (l + r >> 1)

int ls[40 * N], rs[40 * N];

map<int, int> a;
int b[N], n, q, M, top = 1;

segment merge(segment x, segment y) {
    segment ans;
    if (x.l <= 0) return y;
    if (y.l <= 0) return x;
    if (y.l - x.r == 2) {
        ans.l = x.l;
        ans.r = y.r;
    } 
    return ans;
}


void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        if (v) {
            tree[node].l = l;
            tree[node].r = l;
        } else {
            tree[node].l = tree[node].r = -10;
        }
        
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node] = merge(tree[ls[node]], tree[rs[node]]);
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    } 
    segment ans;
    if (ql <= m) ans = merge(ans, query(ql, qr, l, m, ls[node]));
    if (qr > m) ans = merge(ans, query(ql, qr, m + 1, r, rs[node]));
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &M, &q);
    int rt = 0;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &b[i]);
        update(1, b[i], 1, n, rt);
        a[b[i]] = 1;
    }
   // cout << tree[rt].cont << endl;

    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x; scanf("%d", &x);
            if (a[x] == 1) {
                update(0, x, 1, n, rt);
                a[x] = 0;
            } else {
                update(1, x, 1, n, rt);
                a[x] = 1;
            }
        } else {
            int l, r; scanf("%d %d", &l, &r);
            if (a[l] == 0) {
                segment ans = query(l, r, 1, n, rt);
                int cnt = r - l + 1;
                if (cnt % 2 == 0) {
                    if (ans.l == l + 1 && ans.r == r) {
                        puts("Yes");
                    } else {
                        puts("No");
                    }
                } else {
                    if (ans.l == l + 1 && ans.r == r - 1) {
                        puts("Yes");
                    } else {
                        puts("No");
                    }
                }
                
            } else {
                segment ans = query(l, r, 1, n, rt);
                int cnt = (r - l + 1);
                if (cnt % 2 == 0) {
                    if (ans.l == l && ans.r == r - 1) {
                        puts("Yes");
                    } else {
                        puts("No");
                    }
                } else {
                    if (ans.l == l && ans.r == r) {
                        puts("Yes");
                    } else {
                        puts("No");
                    }
                }
               
            }
        }
    }
}