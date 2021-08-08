#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct Splay {
    int l, r, value, sz, cnt;
} tree[20 *N];

int rt, top = 1;

void print(int now) {
    if (!now) return;
    cout << "value " << tree[now].value << " sz " << tree[now].sz << endl;
    print(tree[now].l);
    print(tree[now].r);
}

void push_up(int now) {
    tree[now].sz = tree[now].cnt + tree[tree[now].l].sz + tree[tree[now].r].sz;
}

void zig(int &now) {
 //   cout << "zig = " << tree[now].value << endl;
    int l = tree[now].l;
    tree[now].l = tree[l].r;
    tree[l].r = now;
    now = l;    
    push_up(tree[now].r);
    push_up(now);
}

void zag(int &now) {
  //  cout << "zag = " << tree[now].value << endl;
    int r = tree[now].r;
    tree[now].r = tree[r].l;
    tree[r].l = now;
    now = r;
    push_up(tree[now].l);
    push_up(now);  
}

void splay(int base, int &now) {
    if (base == now) return;
    int &l = tree[now].l, &r = tree[now].r;
    if (base == l) {
        zig(now);
    } else if (base == r) {
        zag(now);
    } else {
        if (tree[base].value < tree[now].value) {
            if (tree[base].value < tree[l].value) {
                splay(base, tree[l].l);
                zig(now);
                zig(now);
            } else {
                splay(base, tree[l].r);
                zag(l);
                zig(now);
            }
        } else {
            if (tree[base].value > tree[r].value) {
                splay(base, tree[r].r);
                zag(now);
                zag(now);
            } else {
                splay(base, tree[r].l);
                zig(r);
                zag(now);
            }
        }
    }
}

void insert(int v, int &now) {
    if (!now) {
        now = top++;
        tree[now].cnt++;
        tree[now].value = v;
        tree[now].sz = 1;
        splay(now, rt);
        return;
    }
    tree[now].sz++;
    if (tree[now].value > v) {
        insert(v, tree[now].l);
    } else if (tree[now].value < v) {
        insert(v, tree[now].r);
    } else {
        tree[now].cnt++;
        splay(now, rt);
    }
}

void del(int x, int now) {
    if (x < tree[now].value) {
      //  cout <<"L " << endl;
        del(x, tree[now].l);
    } else if (x > tree[now].value) {
        //cout << "R " << endl;
        del(x, tree[now].r);
    } else {
        splay(now, rt);
       // print(rt);
        if (tree[rt].cnt > 1) {
            tree[rt].cnt--;
            tree[rt].sz--;
        } else if (tree[rt].l && tree[rt].r){
            int p = tree[rt].r;
            while (tree[p].l) p = tree[p].l;
            splay(p, tree[rt].r);
            tree[tree[rt].r].l = tree[rt].l;
            rt = tree[rt].r;
            push_up(rt);
        } else if (tree[rt].l) {
            rt = tree[rt].l;
        } else if (tree[rt].r) {
            rt = tree[rt].r;
        } else {
            rt = 0;
        }
        return;
    }
}

int get_rank(int v, int now) {
    if (!now) return 0;
    if (tree[now].value > v) {
        return get_rank(v, tree[now].l);
    } else if (tree[now].value < v) {
        return get_rank(v, tree[now].r) + tree[now].sz - tree[tree[now].r].sz;
    } else {
        return tree[tree[now].l].sz;
    }
}

int get_num(int x, int now) {
    if (!now) return 0;
    if (tree[tree[now].l].sz + tree[now].cnt >= x && tree[tree[now].l].sz < x) {
        return tree[now].value;
    }
    if (tree[tree[now].l].sz >= x) {
        return get_num(x, tree[now].l);
    } else {
        return get_num(x - tree[tree[now].l].sz - tree[now].cnt, tree[now].r);
    }
}

int get_cnt(int x, int now) {
    if (!now) {
        return 0;
    }
    if (tree[now].value > x) {
        return get_cnt(x, tree[now].l);
    } else if (x > tree[now].value) {
        return get_cnt(x, tree[now].r);
    } else {
        return tree[now].cnt;
    }
}

void find(int x, int now) {
    if (!now) return;
    if (tree[now].value < x) {
        find(x, tree[now].r);
    } else if (tree[now].value > x) {
        find(x, tree[now].l);
    } else {
        splay(now, rt);
    }
}

int main() {
    int q, n; scanf("%d %d",&n, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        insert(x, rt);
    }
    int last = 0, ans = 0;
    while (q--) {
        int op, x;
        scanf("%d %d", &op, &x);
        x = x ^ last;
        if (op == 1) {
            insert(x, rt);
        } else if (op == 2) {
            del(x, rt);
        } else if (op == 3) {
            last = get_rank(x, rt) +1;
            ans ^= last;
            find(x, rt);
        } else if (op == 4){
            last = get_num(x, rt);
            ans ^= last;
            find(x, rt);
        } else if (op == 5) {
            int cnt = get_cnt(x, rt);
            last = get_num(get_rank(x, rt), rt);
            ans ^= last;
            find(x, rt);
        } else {
            int cnt = get_cnt(x, rt);
    
            last = get_num(get_rank(x, rt) + cnt + 1, rt);
            ans ^= last;
            find(x, rt);
        }
       // print(rt);
    }
    printf("%d\n", ans);
}


