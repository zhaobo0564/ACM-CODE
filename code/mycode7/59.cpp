#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;

int tree[4 * N], n, Q, a[N], k, b[N], c[4 * N];

int ans[N], res = 0;

vector<int> g;

struct qu {
    int l, r, id;
}q[N];

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int low_bit(int x) {
    return x & (-x);
}

void update(int pos, int v) {
    while (pos <= n) {
        tree[pos] += v;
        pos += low_bit(pos);
    }
}

int query(int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += tree[pos];
        pos -= low_bit(pos);
    }
    return sum;
}




int block[N];

bool cmp(qu x, qu y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}

void add(int pos) {
    res += query(b[pos]) - query(c[pos] - 1);
    update(a[pos], 1);
}

void del(int pos) {
    update(a[pos], -1);
    res -= query(b[pos]) - query(c[pos] - 1);
}

int main() {
    scanf("%d %d %d", &n, &Q, &k);
    int bl = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
        g.push_back(a[i] + k);
        g.push_back(a[i] - k);
        block[i] = i / bl;
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for (int i = 1; i <= n; i++) {
        b[i] = get_id(a[i] + k);
        c[i] = get_id(a[i] - k);
        a[i] = get_id(a[i]);
    }
  
    for (int i = 1; i <= Q; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + Q + 1, cmp);
    int l = 1, r = 0;
    n = g.size() + 1;
    for (int i = 1; i <= Q; i++) {

        while (r < q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(--l);
        }
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", ans[i]);
    }


}