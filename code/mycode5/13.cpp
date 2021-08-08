    #include<bits/stdc++.h>
    using namespace std;
    const int N = 1e5 + 7;
     
    int a[N], n, q, top = 1, rt[N];
    #define m (l + r) / 2
     
    vector<pair<int, int> > v;
     
     
    struct hjt {
        int l, r, sum;
        int lone, rone;
        int len;
    }tree[24 * N];
     
    bool cmp(pair<int,int> x, pair<int, int> y) {
        return x.first > y.first;
    }
     
    void push_up(int node) {
        if (tree[tree[node].l].len == tree[tree[node].l].lone) {
            tree[node].lone = tree[tree[node].l].len + tree[tree[node].r].lone;
        } else {
            tree[node].lone = tree[tree[node].l].lone;
        }
        if (tree[tree[node].r].len == tree[tree[node].r].rone) {
            tree[node].rone = tree[tree[node].r].len + tree[tree[node].l].rone;
        } else {
            tree[node].rone = tree[tree[node].r].rone;
        }
        tree[node].sum = max(tree[node].lone, tree[node].rone);
        tree[node].sum = max(tree[node].sum, tree[tree[node].l].rone + tree[tree[node].r].lone);
        tree[node].sum = max(tree[node].sum, max(tree[tree[node].l].sum, tree[tree[node].r].sum));
    }
     
    void update(int pos, int last, int &now, int l, int r) {
        now = top++;
        tree[now] = tree[last];
        tree[now].len = r - l + 1;
        tree[last].len = r - l + 1;
        if (l == r) {
            tree[now].sum = 1;
            tree[now].lone = tree[now].rone = 1;
            return;
        }
        if (pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
        else update(pos, tree[last].r, tree[now].r, m + 1, r);
        push_up(now);
    }
     
    hjt merg(hjt x, hjt y) {
        hjt z;
     
        if (x.len == 0) return y;
        if (x.len == x.lone) {
            z.lone = x.len + y.lone;
        } else {
            z.lone = x.lone;
        }
        if (y.rone == y.len) {
            z.rone = y.len + x.rone;
        } else {
            z.rone = y.rone;
        }
        z.len = x.len + y.len;
        z.sum = max(z.lone, z.rone);
        z.sum = max(x.rone + y.lone, z.sum);
        z.sum = max(z.sum, max(x.sum, y.sum));
        return z;
    }
     
    hjt query(int now, int ql, int qr, int l, int r) {
        if (ql <= l && qr >= r) {
            return tree[now];
        }
        hjt ans;
        ans.l = ans.len = ans.lone = ans.rone = ans.r = ans.sum = 0;
        if(ql <= m) ans = merg(ans, query(tree[now].l, ql, qr, l, m));
        if(qr > m) ans = merg(ans, query(tree[now].r, ql, qr, m + 1, r));
        return ans;
    }
     
     
     
    int main() {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; i++) {
            update(v[i].second, rt[i], rt[i + 1], 1, n);
        }
        scanf("%d", &q);
        while (q--) {
            int ql, qr, w;
            scanf("%d %d %d", &ql, &qr, &w);
            int l = 1, r = n, ans = 0;
            while (l <= r) {
                if (query(rt[m], ql, qr, 1, n).sum >= w) {
                    ans = m; 
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            printf("%d\n", v[ans - 1].first);
        }
        
     
     
    }