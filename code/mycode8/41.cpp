#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, m;
struct node {
    int l, r, k;
}p[N];

bool cmp(node x, node y) {
    return x.r < y.r;
}

int sum[N];

int lowbit(int x) {
    return x & (-x);
}

int query(int x) {
    int res = 0;
    while (x >= 1) {
        res += sum[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x, int v) {
    while (x <= n) {
        sum[x] += v;
        x += lowbit(x);
    }
}

int vis[N];

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].k);
    }
    sort(p + 1, p + m + 1, cmp);

    for (int i = 1; i <= m; i++) {
        int l = p[i].l, r = p[i].r, k = p[i].k;
        int cnt = query(r) - query(l - 1);
        if (cnt >= k) continue;

        for (int j = r; j >= l; j--) {
            if (vis[j] == 0) {
                update(j, 1);
                cnt++;
                vis[j] = 1;
            }
            if (cnt == k) break;

        }
    }
    cout << query(n) << endl;


}