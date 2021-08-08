#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct hjt{
    int sum, l, r;
} tree[40 * N];

int n, q, a[N], rt[N], top = 1;
#define m (l + r) / 2

void update(int pos, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    tree[now].sum++;
    if (l == r) return;
    if (pos <= m) update(pos, l, m, tree[last].l, tree[now].l);
    else update(pos, m + 1, r, tree[last].r, tree[now].r);
}

int query(int k, int l, int r, int last, int now) {
    if (l == r) {
        return l;
    }
    int sum = tree[tree[now].l].sum - tree[tree[last].l].sum;
    int sum1 = tree[tree[now].r].sum - tree[tree[last].r].sum;
    int ans = -1;
    if (sum1 >= k) {
        ans = max(ans, query(k, m + 1, r, tree[last].r, tree[now].r));
    }
    if (sum >= k) {
        ans = max(ans, query(k, l, m, tree[last].l, tree[now].l));
    } 
    return ans;
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()));

    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
        update(a[i], 1, n, rt[i - 1], rt[i]);
    }
    while (q--) {
        int l, r, t;
        scanf("%d %d %d", &l, &r, &t);
        int k = (r - l + 1) / t;
        k++;
        int ans = query(k, 1, n, rt[l - 1], rt[r]);
        if (ans == -1) {
            printf("%d\n", ans);
        } else {
            printf("%d\n", g[ans - 1]);
        }
    } 
    
}
