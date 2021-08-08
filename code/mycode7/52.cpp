#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
typedef long long ll;

struct query {
    int l, r, id;
}q[N];
int block[N];

bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}


ll vis[N], ans[N], res, a[N];

void add(int pos) {
    res -= vis[a[pos]] * vis[a[pos]] * a[pos];
    vis[a[pos]]++;
    res += vis[a[pos]] * vis[a[pos]] * a[pos];
}

void del(int pos) {
    res -= vis[a[pos]] * vis[a[pos]] * a[pos];
    vis[a[pos]]--;
    res += vis[a[pos]] * vis[a[pos]] * a[pos];
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
     int b = sqrt(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        block[i] = i / b;
    
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
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
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", ans[i]);
    }

}