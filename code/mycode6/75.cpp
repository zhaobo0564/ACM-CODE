#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
#define int long long

struct hjt {
    int l, r, sum, lsum, rsum, maxn;
    int flag;
} tree[200 * N];

hjt merg(hjt x, hjt y) {
    hjt ans;
    if (x.l == -1) {
        return y;
    }
    if (x.flag == -1) {
        return y;
    }
    if (y.flag == -1) {
        return x;
    }
    ans.lsum = max(x.lsum, x.sum + y.lsum);
    ans.rsum = max(y.rsum, y.sum + x.rsum);
    ans.sum = x.sum + y.sum;
    ans.maxn = max(ans.lsum, ans.rsum);
    ans.maxn = max(ans.maxn, x.rsum + y.lsum);
    ans.maxn = max(ans.maxn, x.maxn);
    ans.maxn = max(ans.maxn, y.maxn);
    ans.l = 0;
    ans.flag = 1;
    return ans;
}

int rt[N], top = 1, n, q;

#define m (l + r) / 2

void update(int pos, int v, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        if (v < -N) {
            tree[now].flag = -1;
        } else {
            tree[now].maxn = tree[now].lsum = tree[now].rsum = tree[now].sum = v;
            tree[now].flag = 1;
        }
        
        return;
    }
    if (pos <= m) update(pos, v, tree[last].l, tree[now].l, l, m);
    else update(pos, v, tree[last].r, tree[now].r, m + 1, r);

    if (tree[tree[now].l].flag == -1 && tree[tree[now].r].flag == -1) {
        tree[now].flag = -1;
    } else if (tree[now].l == 0) {
        if (tree[tree[now].r].flag == -1) {
            tree[now].flag = -1;
        } else {
            tree[now].lsum = tree[tree[now].r].lsum;
            tree[now].maxn = tree[tree[now].r].maxn;
            tree[now].rsum = tree[tree[now].r].rsum;
            tree[now].sum = tree[tree[now].r].sum;
            tree[now].flag = 1;
        }
    } else if (tree[now].r == 0) {
        if (tree[tree[now].l].flag == -1) {
            tree[now].flag = -1;
        } else {
            tree[now].lsum = tree[tree[now].l].lsum;
            tree[now].maxn = tree[tree[now].l].maxn;
            tree[now].rsum = tree[tree[now].l].rsum;
            tree[now].sum = tree[tree[now].l].sum;
            tree[now].flag = 1;
        }
       
     } else if (tree[tree[now].l].flag == -1) {
        tree[now].lsum = tree[tree[now].r].lsum;
        tree[now].maxn = tree[tree[now].r].maxn;
        tree[now].rsum = tree[tree[now].r].rsum;
        tree[now].sum = tree[tree[now].r].sum;
        tree[now].flag = 1;
     }  else if (tree[tree[now].r].flag == -1) {
        tree[now].lsum = tree[tree[now].l].lsum;
        tree[now].maxn = tree[tree[now].l].maxn;
        tree[now].rsum = tree[tree[now].l].rsum;
        tree[now].sum = tree[tree[now].l].sum;
        tree[now].flag = 1;
     }else {
        int cl = tree[now].l;
        int cr = tree[now].r;
        tree[now] = merg(tree[tree[now].l], tree[tree[now].r]);
        tree[now].l = cl, tree[now].r = cr;
        tree[now].flag = 1;
    }

}

int a[N];
hjt ans;

void query(int ql, int qr, int l, int r, int now) {
    if (ql <= l && qr >= r) {
        if (ans.l == -1) {
            ans = tree[now];
        } else {
            ans = merg(ans, tree[now]);
        }
        //cout << tree[now].lsum << " " << tree[now].rsum << " " << tree[now].maxn << endl;
        return;
    }

    if (ql <= m) query(ql, qr, l, m, tree[now].l);
    if (qr > m) query(ql, qr, m + 1, r, tree[now].r);
}

map<int, int> vis;

int32_t main() {
    int n, q;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    int l = -N, r = N;
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] == 0) {
            update(i, a[i], rt[i - 1], rt[i], l, r);
        } else {
            cout << ")))\n";
            cout << a[i] << endl;
            int temp;
            update(vis[a[i]], -1000000000, rt[i - 1], temp, l, r);
            update(i, a[i], temp, rt[i], l, r);
        }
        vis[a[i]] = i;
    }
    scanf("%lld", &q);
    while (q--) {
        int ll, rr;
        scanf("%lld %lld", &ll, &rr);
        ans.l = -1;
        query(ll,rr, l, r, rt[rr]);
        printf("%lld\n", ans.maxn);
        
    }
    
}