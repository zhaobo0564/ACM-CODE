#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
#define int long long

#define m (l + r) / 2

struct Splay {
    int l, r, sz, value, sum;
}tree[N];

int top = 1, n, q, flag[N], rt, a[N];

void push_up(int now) {
    tree[now].sz = tree[tree[now].l].sz + tree[tree[now].r].sz + 1;
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum + tree[now].value;
}

void push_down(int now) {
    if (flag[now]) {
        tree[tree[now].l].sum += tree[tree[now].l].sz * flag[now];
        tree[tree[now].r].sum += tree[tree[now].r].sz * flag[now];
        tree[tree[now].l].value += flag[now];
        tree[tree[now].r].value += flag[now];
        flag[tree[now].l] += flag[now];
        flag[tree[now].r] += flag[now];
        flag[now] = 0;
    }
}

void zag(int &now) {
    int r = tree[now].r;
    tree[now].r = tree[r].l;
    tree[r].l = now;
    now = r;
    push_up(tree[now].l);
    push_up(now);
}

void zig(int &now) {
    int l = tree[now].l;
    tree[now].l = tree[l].r;
    tree[l].r = now;
    now = l;
    push_up(tree[now].r);
    push_up(now);
}


void splay(int pos, int &now) {
    push_down(now);
    if (1 + tree[tree[now].l].sz == pos) return;
    int &l = tree[now].l, &r = tree[now].r;
    push_down(l), push_down(r);
    if (pos == tree[tree[l].l].sz + 1) {
        zig(now);
    } else if (pos - tree[l].sz - 1 - tree[tree[r].l].sz == 1) {
        zag(now);
    } else {
        if (pos <= tree[l].sz) {
            if (pos <= tree[tree[l].l].sz) {
                splay(pos, tree[l].l);
                zig(now);
                zig(now);
            } else {
                splay(pos - tree[tree[l].l].sz - 1, tree[l].r);
                zag(l);
                zig(now);
            }
        } else {
            pos = pos - tree[l].sz - 1;
            if (pos <= tree[tree[r].l].sz) {
                splay(pos, tree[r].l);
                zig(r);
                zag(now);
            } else {
                splay(pos - tree[tree[r].l].sz - 1, tree[r].r);
                zag(now);
                zag(now);
            }
        }
    }
}




void build(int l, int r, int &now) {
    if (l > r) return;
    now = top++;
    tree[now].sz++;
    tree[now].value = a[m];
    tree[now].sum = a[m];
    build(l, m - 1, tree[now].l);
    build(m + 1, r, tree[now].r);
    push_up(now);
}



void work(int l, int r, int v) {
    splay(l, rt);
    push_down(rt);
    splay(r - tree[tree[rt].l].sz - 1, tree[rt].r);
    flag[tree[tree[rt].r].l] += v;
    tree[tree[tree[rt].r].l].sum += v * tree[tree[tree[rt].r].l].sz;
    tree[tree[tree[rt].r].l].value += v;
    push_up(tree[rt].r);
    push_up(rt);
}

void insert(int pos) {
    splay(pos, rt);
    int p = tree[rt].l;
    push_down(p);
    if (p == 0) {
        tree[top].sum = 0;
        tree[top].sz = 1;
        tree[top].value = 0;
        tree[rt].l = top++;
        push_up(rt);
    } else {
        tree[rt].sz++;
        tree[p].sz++;
        while (tree[p].r) p = tree[p].r, tree[p].sz++, push_down(p);
        tree[top].sum = 0;
        tree[top].sz = 1;
        tree[top].value = 0;
        tree[p].r = top++;
    }
}

int query(int l, int r) {
    splay(l, rt);
    push_down(rt);
    splay(r - tree[tree[rt].l].sz - 1, tree[rt].r);
    return tree[tree[tree[rt].r].l].sum;
}


int32_t main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    n++;


    build(0, n, rt);
    scanf("%lld", &q);
    while (q--) {
       int op; scanf("%lld", &op);
       if (op == 1) {
           int x; scanf("%lld", &x);
           insert(x + 1);
       } else if (op == 2) {
           int l, r, w;
           scanf("%lld %lld %lld", &l, &r, &w);
           work(l, r + 2, w);
       } else {
           int l, r; scanf("%lld %lld", &l, &r);
           printf("%lld\n", query(l, r + 2));
       }
        
    } 
}

