#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

struct splay {
    int l, r, sz, cnt, value;
} tree[N];

int top = 1, rt;

void print(int now) {
    // if (!now) return;
    // cout << "value = " << tree[now].value << " sz " << tree[now].sz << endl;
    // print(tree[now].l);
    // print(tree[now].r);
}

void push_up(int now) {
    tree[now].sz = tree[now].cnt + tree[tree[now].l].sz + tree[tree[now].r].sz;
}

void zig(int &now) {
    int l = tree[now].l;
    tree[now].l = tree[l].r;
    tree[l].r = now;
    now = l;
    push_up(tree[now].r);
    push_up(now);
}

void zag(int &now) {
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
    if (l == base) {
        zig(now);
    } else if (r == base) {
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
            if (tree[base].value < tree[r].value) {
                splay(base, tree[r].l);
                zig(r);
                zag(now);
            } else {
                splay(base, tree[r].r);
                zag(now);
                zag(now);
            }
        }
    }
}

void insert(int x, int &now) {
    if (!now) {
        now = top++;
        tree[now].cnt++;
        tree[now].sz++;
        tree[now].value = x;
        splay(now, rt);
        return;
    } 
    tree[now].sz++;
    if (x < tree[now].value) {
        insert(x, tree[now].l);
    } else if (x > tree[now].value) {
        insert(x, tree[now].r);
    } else {
        tree[now].cnt++;
        splay(now, rt);
    } 
}

void del(int x, int now) {
    if (!now) {
        return;
    }
    if (x < tree[now].value) {
        del(x, tree[now].l);
    } else if (x > tree[now].value) {
        del(x, tree[now].r);
    } else {
        splay(now, rt);
        if (tree[rt].cnt > 1) {
            tree[rt].cnt--;
            tree[rt].sz--;
        } else if (tree[rt].l && tree[rt].r) {
            int p = tree[rt].l;
            while (tree[p].r) p = tree[p].r;
            splay(p, tree[rt].l);
            tree[tree[rt].l].r = tree[rt].r;
            rt = tree[rt].l;
            push_up(rt);
        } else if (tree[rt].l) {
            rt = tree[rt].l;
        } else if (tree[rt].r) {
            rt = tree[rt].r;
        } else {
            rt = 0;
        }
        
    }
}

void find(int x, int now) {
    if (!now) return;
    if (x < tree[now].value) {
        find(x, tree[now].l);
    } else if (x > tree[now].value) {
        find(x, tree[now].r);
    } else {
        splay(now, rt);
    }
}

int get_rank(int x) {
    insert(x, rt);
    print(rt);
    int ans = tree[tree[rt].l].sz;
    del(x, rt);
    return ans;
}

int get_num(int x, int now) {
    if (!now) return 0;
    if (tree[tree[now].l].sz < x && tree[tree[now].l].sz + tree[now].cnt >= x) {
        return tree[now].value;
    } 
    if (tree[tree[now].l].sz >= x) {
        return get_num(x, tree[now].l);
    } else {
        return get_num(x - (tree[tree[now].l].sz + tree[now].cnt), tree[now].r);
    }
}



int main() {
    int q, n; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        insert(x, rt);
    }
    int res = 0, last = 0;
    while (q--) {
        int op, x, ans = -1;
        scanf("%d %d", &op, &x);
        x = last ^ x;
       // printf("x = %d\n", x);
        if (op == 1) {
            insert(x, rt);
        } else if (op == 2) {
            del(x, rt);
        } else if (op == 3) {
            ans = get_rank(x) + 1;
            res = res ^ ans;
            last = ans;
        } else if (op == 4) {
            ans = get_num(x, rt);
            res = res ^ ans;
            last = ans;
        } else if (op == 5) {
            ans = get_rank(x);
            ans = get_num(ans, rt);
            last = ans;
            res = res ^ ans;
        } else {
            find(x, rt);
            int cnt = 0;
            if (tree[rt].value == x) 
                cnt = tree[rt].cnt;
            ans = get_rank(x);
           // cout << "ans " << ans << endl;
            ans = ans + cnt + 1;
            //cout << "ANS " << ans << endl;
            ans = get_num(ans, rt);
            last = ans;
            res = res ^ ans;
        }
    }
    printf("%d\n", res);
}



