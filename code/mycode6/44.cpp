#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

int n, q, k, a[N], tree[4 * N][3];
int flag[4 * N][3];

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node][v] = 1;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node][v] = tree[lson][v] + tree[rson][v];
}

void push_down(int node, int nl, int nr) {
    if (flag[node][0]) {
        tree[lson][0] = tree[lson][1] = tree[lson][2] = 0;
        tree[lson][0] = nl;
        tree[rson][0] = tree[rson][1] = tree[rson][2] = 0;
        tree[rson][0] = nr;
        flag[lson][0] = flag[lson][1] = flag[lson][2] = 0;
        flag[lson][0] = 1;
        flag[rson][0] = flag[rson][1] = flag[rson][2] = 0;
        flag[rson][0] = 1;
        flag[node][0] = 0;
    }

    if (flag[node][1]) {
        tree[lson][0] = tree[lson][1] = tree[lson][2] = 0;
        tree[lson][1] = nl;
        tree[rson][0] = tree[rson][1] = tree[rson][2] = 0;
        tree[rson][1] = nr;
        flag[lson][0] = flag[lson][1] = flag[lson][2] = 0;
        flag[lson][1] = 1;
        flag[rson][0] = flag[rson][1] = flag[rson][2] = 0;
        flag[rson][1] = 1;
        flag[node][1] = 0;
    }

    if (flag[node][2]) {
        tree[lson][0] = tree[lson][1] = tree[lson][2] = 0;
        tree[lson][2] = nl;
        tree[rson][0] = tree[rson][1] = tree[rson][2] = 0;
        tree[rson][2] = nr;
        flag[lson][0] = flag[lson][1] = flag[lson][2] = 0;
        flag[lson][2] = 1;
        flag[rson][0] = flag[rson][1] = flag[rson][2] = 0;
        flag[rson][2] = 1;
        flag[node][2] = 0;
    }


}

void update(int v, int ql, int qr, int l, int r, int node) {
    if (qr < ql) return;
    if (ql <= l && qr >= r) {
        tree[node][0] = 0;
        tree[node][1] = 0;
        tree[node][2] = 0;
        tree[node][v] = (r - l + 1);
        flag[node][0]= 0;
        flag[node][1] = 0;
        flag[node][2] = 0;
        flag[node][v] = 1;

        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node][0] = tree[lson][0] + tree[rson][0];
    tree[node][1] = tree[lson][1] + tree[rson][1];
    tree[node][2] = tree[lson][2] + tree[rson][2];
}

int zero, one, two;

void query(int ql, int qr, int l, int r , int node) {
    if (ql <= l && qr >= r) {
        zero += tree[node][0];
        one += tree[node][1];
        two += tree[node][2];
        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) query(ql, qr, l, m, lson);
    if (qr > m) query(ql, qr, m + 1, r, rson);
}

int query(int pos, int l, int r, int node) {
    if (l == r) {
        if (tree[node][1]) return 1;
        return 0;
    }
    push_down(node, l - m + 1, r - m);
    if (pos <= m) return query(pos, l, m, lson);
    return query(pos, m + 1, r, rson);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        memset(flag, 0, sizeof(flag));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d %d", &n, &q, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] < a[k]) {
                update(0, i, 1, n, 1);
            } else if (a[i] == a[k]) {
                update(1, i, 1, n, 1);
            } else {
                update(2, i, 1, n, 1);
            }
        }
        while (q--) {
            int op, l, r;
            scanf("%d %d %d", &op, &l, &r);
            if (op == 0) {
                zero = one = two = 0;
                query(l, r, 1, n, 1);
                update(0, l, l + zero - 1, 1, n, 1);
                update(1, l + zero, l + zero + one - 1, 1, n, 1);
                update(2, l + zero + one, r, 1, n, 1);
            } else {
                zero = one  = two = 0;
                query(l, r, 1, n, 1);
                update(2, l, l + two - 1, 1, n, 1);
                update(1, l + two , l + two + one - 1, 1, n, 1);
                update(0, l + two + one, r, 1, n, 1);
            }
        }
         for (int i = 1; i <= n; i++) {
            if (query(i, 1, n, 1)) {
                printf("%d\n", i);
                break;
            }
        }


    }
    

   
}