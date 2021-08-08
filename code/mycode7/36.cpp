#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 1e5 + 7;
struct query {
    int l, r, pos;
}q[N];

typedef long long ll;
ll n, a[N], vis[N], res = 0, m, ans[N];
int block[N];

vector<ll> g;

bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}

int get_id(ll x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

void add(int pos) {
    res -= vis[a[pos]] * vis[a[pos]] * vis[a[pos]];
    vis[a[pos]]++;
    res += vis[a[pos]] * vis[a[pos]] * vis[a[pos]];
}

void del(int pos) {
    res -= vis[a[pos]] * vis[a[pos]] * vis[a[pos]];
    vis[a[pos]]--;
    res += vis[a[pos]] * vis[a[pos]] * vis[a[pos]];
}


int main() {

    while(~scanf("%lld", &n)){
        g.clear();
        res = 0;
        for (int i = 0; i <= n + 10; i++) {
            vis[i] = 0;
        }
        int b = sqrt(n*1.0);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            g.push_back(a[i]);
            block[i] = i / b;
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for (int i = 1; i <= n; i++) {
            a[i] = get_id(a[i]);
        }
        scanf("%lld", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &q[i].l, &q[i].r);
            if (q[i].l > q[i].r) swap(q[i].l, q[i].r);
            q[i].pos = i;
        }
        sort(q + 1, q + m + 1, cmp);
        int l = 1, r = 0;
        for (int i = 1; i <= m; i++) {
            while (l < q[i].l) {
                del(l++);
            }
            while (l > q[i].l) {
                add(--l);
            }
            while (r < q[i].r) {
                add(++r);
            }
            while (r > q[i].r) {
                del(r--);
            }
            ans[q[i].pos] = res;
        }
        for (int i = 1; i <= m; i++) {
            printf("%lld\n", ans[i]);
        }
    }


}