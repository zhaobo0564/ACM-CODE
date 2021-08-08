#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define m (l + r) / 2

int a[N], n, q, top = 1, rt[N], root[N];

struct qu{
    int l, r, k;
}que[N];

struct hjt{
    int l, r, sum;
}tree[200 * N];

vector<int> la, no, g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int lowbit(int x) {
    return x & -x;
}

void update(int v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    tree[now].sum += v;
    if (l == r) return ;
    if (pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
}

int query(int k, int last, int now, int l, int r){
    if (l == r) return l;
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    for (int i = 0; i < no.size(); i++) {
        sum += tree[tree[no[i]].l].sum;
    }
    for (int i = 0; i < la.size(); i++) {
        sum -= tree[tree[la[i]].l].sum;
    }
    if (sum >= k) {
        for (int i = 0; i < no.size(); i++) {
            no[i] = tree[no[i]].l;
        }
        for(int i = 0; i < la.size(); i++) {
            la[i] = tree[la[i]].l;
        }
        return query(k, tree[last].l, tree[now].l, l, m);
    }
    for (int i = 0; i < no.size(); i++) {
        no[i] = tree[no[i]].r;
    }
    for (int i = 0; i < la.size(); i++) {
        la[i] = tree[la[i]].r;
    }
    return query(k - sum, tree[last].r, tree[now].r, m + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    int maxn = 100000;
    for (int i = 1; i <= n; i++) {
        update(1, a[i], rt[i - 1], rt[i], 1, maxn);
    }
    for (int i = 1; i <= q; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
           int l, r, k;
           no.clear(), la.clear();
           scanf("%d %d %d", &l, &r, &k);
           for (int j = r; j; j -= lowbit(j)) {
               no.push_back(root[j]);
           }
           for (int j = l - 1; j; j -= lowbit(j)) {
               la.push_back(root[j]);
           }
           k = (r - l + 1) - k + 1;
           printf("%d\n", query(k,rt[l - 1], rt[r], 1, maxn));
        } else {
            int pos, v;
            scanf("%d %d", &pos, &v);
            for (int j = pos; j <= n; j += lowbit(j)) {
               update(-1, a[pos], root[j], root[j], 1, maxn); 
            }
            a[pos] = v;
            for (int j = pos; j <= n; j += lowbit(j)) {
                update(1, a[pos], root[j], root[j], 1, maxn);
            }
        }
    }
    
}

    
    
    
    
    
    
    