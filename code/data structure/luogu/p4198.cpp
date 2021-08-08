#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

struct segment{
    int len;
    double maxn;
}tree[4 * N];

int work(double k, int l, int r, int node) {

    if (l == r) {
        return 0;
    }
    if (tree[lson].maxn > k) {
        return work(k, l, m, lson);
    } else {
        if (tree[rson].len == tree[node].len) {
            return work(k, m + 1, r, rson);
        }
        return work(k, m + 1, r, rson) + tree[node].len - tree[rson].len;
    }

}

void update(int pos, double v, int l, int r, int node) {
    if (l == r) {
        tree[node].len = 1;
        tree[node].maxn = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    if (tree[rson].maxn <= tree[lson].maxn) {
        tree[node].len = tree[lson].len;
    } else {
        tree[node].len = tree[lson].len + tree[rson].len  - work(tree[lson].maxn, m + 1, r, rson);
    }
   
}


int main() { 
    int n, q;
    scanf("%d %d", &n, &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        update(x, (double)y / (double)x, 1, n, 1);
        printf("%d\n", tree[1].len);
    }
    
}

