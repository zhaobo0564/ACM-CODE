#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
struct node {
    int a, b, c;
}p[N];

int sum[N], n;

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int v) {
    while (pos <= n) {
        sum[pos] += v;
        pos += lowbit(pos); 
    }
}

int query(int l, int r) {
    int res = 0;
    while (r > 0) {
        res += sum[r];
        r -= lowbit(r);
    }
    l--;
    while (l > 0) {
        res -= sum[l];
        l -= lowbit(l);
    }
    return res;
}



bool cmp(node x, node y) {
    return x.a < y.a;
}

struct data {
    int f, a, b, c;
};

bool cmp1(data x, data y) {
    if (x.b == y.b) {
        return x.f < y.f;
    }
    return x.b < y.b;
}

vector<data> g;

#define m (l + r) / 2

ll ans = 0;

void CDQ(int l, int r) {
    if (l == r) return;
    g.clear();
    for (int i = l; i <= m; i++) {
        g.push_back({0, p[i].a, p[i].b, p[i].c});
    }

    for (int i = m + 1; i <= r; i++) {
        g.push_back({1, p[i].a, p[i].b, p[i].c});
    }

    sort(g.begin(), g.end(), cmp1);
    for (int i = 0; i < g.size(); i++) {
        if (g[i].f == 0) {
            add(g[i].c, 1);
        } else {
            ans += query(1, g[i].c);
        }
    }

    for (int i = 0; i < g.size(); i++) {
        if (g[i].f == 0) {
            add(g[i].c, -1);
        }
    }

    CDQ(l, m);
    CDQ(m + 1, r);
   
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
    }
    sort(p + 1, p + n + 1, cmp);
    CDQ(1, n);
    n--;
    cout << 1ll*(1ll*(n + 1) * 1ll*n /  2) - ans << endl;


}