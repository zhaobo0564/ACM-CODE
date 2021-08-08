#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 70;
typedef long long ll;

struct kd_tree {
    int l, r, sz, v, x, y;
    int minn[2], maxn[2];
    ll sum;
} tree[N];

struct point {
    int x, y, z;
}p[N];

int top = 1;

void push_up(int now) {
    int ls = tree[now].l, rs = tree[now].r;
    tree[now].sz = tree[ls].sz + tree[rs].sz + 1;
    tree[now].sum = tree[ls].sum + tree[rs].sum + tree[now].v;
    for (int i = 0; i < 2; i++) {
        if (ls) {
            tree[now].maxn[i] = max(tree[now].maxn[i], tree[ls].maxn[i]);
            tree[now].minn[i] = min(tree[now].minn[i], tree[ls].minn[i]);
        }
        if (rs) {
            tree[now].maxn[i] = max(tree[now].maxn[i], tree[rs].maxn[i]);
            tree[now].minn[i] = min(tree[now].minn[i], tree[rs].minn[i]);
        }
    }
}

void insert(point v, int f, int &now) {
    if (!now) {
        now = top++;
        tree[now].sz = 1;
        tree[now].v = v.z;
        tree[now].sum = v.z;
        tree[now].x = v.x;
        tree[now].y = v.y;
        tree[now].maxn[0] = tree[now].minn[0] = v.x;
        tree[now].maxn[1] = tree[now].minn[1] = v.y;
        return;
    } 
    if (f == 1) {
        if (v.x < tree[now].x) {
            insert(v, f ^ 1, tree[now].l);
        } else {
            insert(v, f ^ 1, tree[now].r);
        }
    } else {
        if (v.y < tree[now].y) {
            insert(v, f ^ 1, tree[now].l);
        } else {
            insert(v, f ^ 1, tree[now].r);
        }
    }
    push_up(now);
}

int judge(point a, point b, int xmax, int xmin, int ymax, int ymin) {
    if (a.x <= xmin && a.y <= ymin && b.x >= xmax && b.y >= ymax) {
        return 1;
    } 
    if (a.x > xmax || b.x < xmin || b.y < ymin || a.y > ymax) {
        return 0;
    }
    return -1;
}

int query(point a, point b, int now) {
    
    int res = 0;
    int ans = judge(a, b, tree[now].maxn[0], tree[now].minn[0], tree[now].maxn[1], tree[now].minn[1]);
    if (ans == 1) {
        return tree[now].sum;
    } else if (ans == 0) {
        return 0;
    } else {
        if (tree[now].x >= a.x && tree[now].y >= a.y && tree[now].x <= b.x && tree[now].y <= b.y)
            res += tree[now].v;
        if (tree[now].l) res += query(a, b, tree[now].l);
        if (tree[now].r) res += query(a, b, tree[now].r);
    }
    return res;
}


int main() {
    int ans = 0;
    int n; scanf("%d", &n);
    int rt = 0;
    for (int i = 1; i; i++) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
           x ^= ans, y ^= ans, v ^= ans;
            insert({x, y, v}, 1, rt);
        } else if (op == 2){
            int x[2], y[2];
            scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
           x[0] ^= ans, y[0] ^= ans, x[1] ^= ans, y[1] ^= ans;
            printf("%d\n", ans = query({x[0], y[0]}, {x[1], y[1]}, rt));
        } else {
            break;
        }
    }
    return 0;

}
