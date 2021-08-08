#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct hjt {
    int l, r, sum;
} tree[40 * N];

int top = 1, rt[N];

#define m (l + r) / 2

void update(int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
       tree[now].sum = 1;
        return;
    }
    if (pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;

}

int query(int last, int now, int l, int r) {
    if (l == r) return l;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
   // cout << "sum = " << sum << " m - l + 1 " << m - l + 1 << endl;
    if (m - l + 1 > sum) return query(tree[last].l, tree[now].l, l, m);
    else return query(tree[last].r, tree[now].r, m + 1, r);
}
int a[N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        update(a[i], rt[i - 1], rt[i], 0, n + 1);
    }
    while (q--) {
        int l, r; 
        scanf("%d %d", &l, &r);
        printf("%d\n", query(rt[l - 1], rt[r], 0, n + 1));
    }

}