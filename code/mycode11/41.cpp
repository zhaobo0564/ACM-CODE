#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;

#define m (l + r) / 2

struct Splay {
    int l, r, sz, value;
}tree[N];

int top = 1, n, q, flag[N], rt;

void push_up(int now) {
    tree[now].sz = tree[tree[now].l].sz + tree[tree[now].r].sz + 1;
}

void push_down(int now) {
    if (flag[now]) {
        swap(tree[now].l, tree[now].r);
        flag[tree[now].l] ^= flag[now];
        flag[tree[now].r] ^= flag[now];
        flag[now] ^= 1;
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
    tree[now].value = m;
    build(l, m - 1, tree[now].l);
    build(m + 1, r, tree[now].r);
    push_up(now);
}

void w(int now) {
    if (!now) return;
    push_down(now);
    w(tree[now].l);
    if (tree[now].value != 0 && tree[now].value != n)
        cout << tree[now].value << " ";
    w(tree[now].r);
}

void work(int l, int r) {
    splay(l, rt);
    splay(r - tree[tree[rt].l].sz - 1, tree[rt].r);
    flag[tree[tree[rt].r].l] ^= 1;
}

int main() {
    scanf("%d %d", &n, &q);
    n++;
    build(0, n, rt);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        work(l, r + 2);
        
    } 
    w(rt);
    cout << endl;
}