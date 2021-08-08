#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
struct query {
    int l, r, pos;
}q[N];

vector<ll> g;
int n, m, block[N];
ll a[N], ans[N], res = 0, vis[N];

void add(int pos) {
    if (a[pos] > n) return;
    vis[a[pos]]++;
    if (vis[a[pos]] == a[pos]) {
        res++;
    } else if (vis[a[pos]] == a[pos] + 1) {
        res--;
    }
}

void del(int pos) {
    if (a[pos] > n) return; 
    vis[a[pos]]--;
    if (vis[a[pos]] == a[pos]) {
        res++;
    } else if (vis[a[pos]] == a[pos] - 1) {
        res--;
    }
}


bool cmp(query x, query y) {
    if (block[x.l] == block[y.l]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}



int main() {
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        block[i] = i / b;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
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