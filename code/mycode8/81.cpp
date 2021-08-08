#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1e5 + 7;

struct Splay {
    int l, r, cnt, sz, value;
}tree[N];

void push_up(int now) {
    tree[now].sz = tree[tree[now].l].sz + tree[tree[now].r].sz + tree[now].cnt;
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
                zag(now);
            }
        } else {
            if (tree[base].value > tree[r].value) {
                splay(base, tree[r].r);
                zag(now);
                zag(now);
            } else {
                splay(base, tree[r].l);
                zig(r);
                zig(now);
            }
        }
    }
}

int top = 1, rt;

void insert(int x, int &now) {
    if (!now) {
        now = top++;
        tree[now].cnt++;
        tree[now].sz++;
        tree[now].value = x;
        return;
    }
    tree[now].sz++;
    if (x < tree[now].value) {
        insert(x, tree[now].l);
    } else if (x > tree[now].value) {
        insert(x, tree[now].r);
    } else {
        tree[now].cnt++;
    }
}

void del(int x, int now) {
    if (!now) return;
    if (tree[now].value > x) {
        del(x, tree[now].l);
    } else if (tree[now].value < x) {
        del(x, tree[now].r);
    } else {
        splay(now, rt);
        if (tree[rt].cnt > 1) {
            tree[rt].cnt--;
            tree[rt].sz--;
        }
         else if (tree[rt].l && tree[rt].r) {
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

void solve(int x, int now) {
    if (!now) return;
    if (x < tree[now].value) {
        solve(x, tree[now].l);
    } else if (x > tree[now].value) {
        solve(x, tree[now].r);
    } else {
        splay(now, rt);
    }
}

int get_rank(int x) {
    insert(x, rt);
    solve(x, rt);
    int ans = tree[tree[rt].l].sz;
    del(x, rt);
    return ans;
}

int work(int x, int now) {
    if (!now) return 0;
    if (tree[tree[now].l].sz < x && tree[now].cnt + tree[tree[now].l].sz >= x) {
       return tree[now].value;
    }
    if (tree[tree[now].l].sz >= x) {
        return work(x, tree[now].l);
    } else {
       return  work(x - tree[tree[now].l].sz - tree[now].cnt, tree[now].r);
    }

}

int get_num(int x) {
    return work(x, rt);
}

int find(int x, int now) {
    if (!now) return 0;
    if (x < tree[now].value) {
        return find(x, tree[now].l);
    } else if (x > tree[now].value) {
        return find(x, tree[now].r);
    } else {
        return tree[now].cnt;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        insert(x, rt);
    }
    int last = 0, ans = 0;
    while (q--) {
        int op, x;
        scanf("%d %d", &op, &x);
        x = last ^ x;
        if (op == 1) {
            insert(x, rt);
        } else if (op == 2) {
            del(x, rt);
        } else if (op == 3) {
            int res = (get_rank(x) + 1);
            cout << res << endl;
            last = res;
            ans = ans ^ (get_rank(x) + 1);
        } else if (op == 4) {
            int res = get_num(x);
            ans = ans ^ res;
            last = res;
            if (res) solve(x, rt);
        } else if (op == 5) {
            int cnt = get_rank(x);
        
            int res = get_num(cnt);
            ans = ans ^ res;
            last = res;
            if (res) solve(x, rt);
        } else {
            int cnt = find(x, rt);
            int ra = get_rank(x);
            int res = get_num(ra + cnt + 1);
            ans = ans ^ res;
            last = res;
            if (res) solve(x, rt);
        }
    }
    printf("%d\n", ans);
}