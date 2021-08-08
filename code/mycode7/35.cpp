#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
int a[N], vis[N], block[N];
pair<long long, long long> ans[N];
long long res = 0;
struct query {
    int l, r;
    int pos;
}q[N];

bool cmp(query x, query y) {
    if (block[x.l] == block[x.r]) {
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}

void del(int pos) {
    if (vis[a[pos]] >= 2) {
        res -= (vis[a[pos]] - 1);
    }
    vis[a[pos]]--;
}

void add(int pos) {
    vis[a[pos]]++;
    if (vis[a[pos]] >= 2) {
        res += (vis[a[pos]] - 1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        block[i] = i / b;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].pos = i;
    }

    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
       // cout << "l = " << q[i].l << " r = " << q[i].r << endl;
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(l--);
        }
        while (r <= q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }

        long long cnt = (q[i].r - q[i].l) * (q[i].r - q[i].l + 1);
        cnt = cnt / 2;
        long long gcd = __gcd(res, cnt);
        ans[q[i].pos] = {res / gcd , cnt / gcd };
        
        
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld/%lld\n", ans[i].first, ans[i].second);
    }

}