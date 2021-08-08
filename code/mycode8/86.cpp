#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;

struct Splay {
    int l, r, sz;
    ll value, sum;
}tree[N];

#define m (l + r) / 2

ll a[N];

void push_up(int now) {
    tree[now].sz = tree[tree[now].l].sz + tree[tree[now].r].sz + 1;
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum + tree[now].value;
}

int top = 1, rt, flag[N];

void build(int l, int r, int &now) {
    if (l > r) return;
    now = top++;
    tree[now].value = a[m];
    tree[now].sz++;
    tree[now].sum = 0;
    build(l, m - 1, tree[now].l);
    build(m + 1, r, tree[now].r);
    push_up(now);
}

void push_down(int now) {
    if (flag[now]) {
        cout <<"now = " << tree[now].value << endl;
        tree[tree[now].l].sum += flag[now] * tree[tree[now].l].sz;
        tree[tree[now].r].sum += flag[now] * tree[tree[now].r].sz;
        tree[tree[now].l].value += flag[now];
        tree[tree[now].r].value += flag[now];
        flag[tree[now].l] += flag[now];
        flag[tree[now].r] += flag[now];
        flag[now] = 0;
    }
}

void zag(int &now) {
    cout << "zag = " << tree[now].value << endl;
    int r = tree[now].r;
    tree[now].r = tree[r].l;
    tree[r].l = now;
    now = r;
    push_up(tree[now].l);
    push_up(now);
}

void zig(int &now) {
    cout << "zig = " << tree[now].value << endl;
    int l = tree[now].l;
    tree[now].l = tree[l].r;
    tree[l].r = now;
    now = l;
    push_up(tree[now].r);
    push_up(now);
}

void splay(int pos, int &now) {
    //cout << "Pos " << pos << " " << tree[now].value << endl;
    push_down(now);
    if (tree[tree[now].l].sz + 1 == pos) {
        cout << "AAAA\n";
        return;
    }
    int &l = tree[now].l, &r = tree[now].r;
    push_down(l), push_down(r);
    if (pos == tree[tree[l].l].sz + 1) {
        zig(now);
    } else if (pos - tree[l].sz - 1 == tree[tree[r].l].sz + 1) {
        zag(now);
    } else {
        if (pos <= tree[l].sz) {
            if (pos <= tree[tree[l].l].sz) {
                cout << "LL" << endl;
                splay(pos, tree[l].l);
                zig(now);
                zig(now);
            } else {
                cout << "LR" << endl;
                splay(pos - tree[tree[l].l].sz - 1, tree[l].r);
                zag(l);
                zig(now);
            } 
        } else {
            pos = pos - tree[l].sz - 1;
            if (pos <= tree[tree[r].l].sz) {
                cout << "RL" << endl;
                splay(pos, tree[r].l);
                zig(r);
                zag(now);
            } else {
                cout << "RR" << endl;
                splay(pos - tree[tree[r].l].sz - 1, tree[r].r);
                zag(now);
                zag(now);
            }
        }
    }
    
}

void print(int now) {
    if (!now) return;
    cout << "value " << tree[now].value << " sum = " << tree[now].sum << " sz = " << tree[now].sz << endl;
    print(tree[now].l);    print(tree[now].r);
}

void insert(int pos, int &now) {
    if (!now) return;
    tree[now].sz++;
    push_down(now);
    cout << "pos = " << pos << " sz " << tree[tree[now].l].sz << endl;
    if (pos == tree[tree[now].l].sz + 1) {
        int p = tree[now].l;
        cout <<"AA " << tree[now].value;
        tree[p].sz++;
        cout << "PPP = " << p << endl;
        if (p) 
            while (tree[p].r) p = tree[p].r, tree[p].sz++;
        else 
            p = now;
        cout << "sz " << tree[p].sz << endl;
        tree[top].sz = 1;
        tree[top].value = 0;
        tree[top].sum = 0;
        tree[p].r = top++;
        cout << "P = " << p <<endl;
        cout << "value = " << tree[p].value << endl;
        cout <<"NODE =  " << tree[p].r << endl;
        return;
    }
    if (pos <= tree[tree[now].l].sz) {
        insert(pos, tree[now].l);
    } else {
        insert(pos - tree[tree[now].l].sz - 1, tree[now].r);
    }
}

void update(int l, int r, int v) {
    splay(l, rt);

    print(rt);

    splay(r - tree[tree[rt].l].sz - 1, tree[rt].r);
    print(rt);
    tree[tree[tree[rt].r].l].sum += v * tree[tree[tree[rt].r].l].sz;
    tree[tree[tree[rt].r].l].value += v;
    flag[tree[tree[rt].r].l] += v;
}

ll query(int ql, int qr) {
    splay(ql, rt);
    print(rt);
    splay(qr - tree[tree[rt].l].sz - 1, tree[rt].r);
    print(rt);
    return tree[tree[tree[rt].r].l].sum;
}





int main() {
    int n, q;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    n++;
    build(0, n, rt);
    print(rt);
    scanf("%d", &q);
    while (q--) {
        int op, l, r, v;
        scanf("%d %d", &op, &l);
        if (op == 1) {
            insert(l + 1, rt);
            puts("AAAA");
            print(rt);
            splay(l + 1, rt);
        } else if (op == 2) {
            scanf("%d %d", &r, &v);
            update(l, r + 2, v);
        } else {
            scanf("%d", &r);
            printf("%lld\n", query(l, r + 2));
        }
        cout << "rt = " << rt << endl;
        print(rt);
    }
    
}