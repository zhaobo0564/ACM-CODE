#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

struct segment{
    int sum, maxn, pos;
    int l, r;
} tree[50 * N];

#define m (l + r) / 2

int top = 1;

void update(int v, int pos, int l, int r, int &now) {
    if (now == 0) {
        now = top++;
    }
    if (l == r) {
        tree[now].maxn = v;
        tree[now].pos = l;
        if (v == 0) {
            tree[now].sum = 0;
        } else if (v == -1){
           tree[now].sum = 1; 
           tree[now].maxn = 0;
           
        } else {
            tree[now].sum = 1;
        }
        
        return;
    }
    if (pos <= m) update(v, pos, l, m, tree[now].l);
    else update(v, pos, m + 1, r, tree[now].r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
    tree[now].maxn = max(tree[tree[now].l].maxn, tree[tree[now].r].maxn);
    if (tree[now].maxn == tree[tree[now].l].maxn) {
        tree[now].pos = tree[tree[now].l].pos;
    } else {
        tree[now].pos = tree[tree[now].r].pos;
    } 
}

int query(int ql, int qr, int l, int r, int now) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        return tree[now].sum;
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, tree[now].l);
    if (qr > m) ans += query(ql, qr, m + 1, r, tree[now].r);
    return ans;
}

int qu(int k, int l, int r, int now) {
    if(l == r) {
        return l;
    }

    if (tree[tree[now].l].sum >= k) {
        return qu(k, l, m, tree[now].l);
    } else {
        return qu(k - tree[tree[now].l].sum, m + 1, r, tree[now].r);
    }
}



int n, q, a[N];

void solve() {
    top = 1;
    for (int i = 0; i < N * 40; i++) {
        tree[i].maxn = -1000;
    }
    int maxn = 2e9 + 7;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int rt = 0;
    update(-1, a[1], 1, maxn, rt);
    for (int i = 2; i <= n; i++) {
        update(a[i] - a[i - 1], a[i], 1, maxn, rt);
    }
    int ans = qu(tree[rt].sum ,1, maxn, 1) - qu(1, 1, maxn, 1);
   // cout << ans << endl;
    cout << ans - tree[rt].maxn << endl;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 0) {
                int an = query(1, x - 1, 1, maxn, rt);
                if (an == 0) {
                    if (tree[rt].sum > 1) {
                         int cn = qu(2, 1, maxn, rt);
                        update(-1, cn, 1, maxn, rt);
                        update(0, x, 1, maxn, rt);
                    } else {
                        update(0, x, 1, maxn, rt);
                    }
                   
                } else {

                
                    int va = qu(an, 1, maxn, rt);
                    if (an + 2 <= tree[rt].sum) {
                        int va1 = qu(an + 2, 1, maxn, rt);
                        update(0, x, 1, maxn, rt);
                        update(va1 - va, va1, 1, maxn, rt);
                    } else {
                        update(0, x, 1, maxn, rt);
                    }
                }
            
        } else {
            int an = query(1, x, 1, maxn, rt); 
            if (an == 0) {
                update(-1, x, 1, maxn, rt);
                if(tree[rt].sum > 1) {
                    int cn = qu(2, 1, maxn, rt);
                    update(cn - x, cn, 1, maxn, rt);
                }
                
            } else {
                int va = qu(an, 1, maxn, rt);
                if (an + 1 <= tree[rt].sum) {
                    int va1 = qu(an + 1, 1, maxn, rt);
                    update(x - va, x, 1, maxn, rt);
                    update(va1 - x, va1, 1, maxn, rt);
                } else {
                    update(x - va, x, 1, maxn, rt);
                }
            }
        }
       // cout << "SA " << tree[rt].maxn << endl;
        ans = qu(tree[rt].sum, 1, maxn, rt) - qu(min(1, tree[rt].sum), 1, maxn, rt);
        cout << ans - tree[rt].maxn << endl;
    }
}



int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    
    while (t--) {
        solve();
    }
}