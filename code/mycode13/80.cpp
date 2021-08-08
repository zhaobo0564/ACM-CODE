#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

struct point {
    double d[2];
    point() {}
    point(int x, int y) {
        this->d[0] = x;
        this->d[1] = y;
    }
}p[N];

struct kd_tree{
    int l, r;
    double d[2], maxn[2], minn[2];
} tree[N];

double dist(point x, point y) {
    return sqrt((x.d[0] - y.d[0]) *(x.d[0] - y.d[0])  + (x.d[1] - y.d[1]) *(x.d[1] - y.d[1]));
}

#define m (l + r >> 1) 

void push_up(int node) {
    int ls = tree[node].l, rs = tree[node].r;
    for (int i = 0; i < 2; i++) {
        if (ls) {
            tree[node].maxn[i] = max(tree[node].maxn[i], tree[ls].maxn[i]);
            tree[node].minn[i] = min(tree[node].minn[i], tree[ls].minn[i]);
        }
        if (rs) {
            tree[node].maxn[i] = max(tree[node].maxn[i], tree[rs].maxn[i]);
            tree[node].minn[i] = min(tree[node].minn[i], tree[rs].minn[i]);
        }
    }
}

int st;
int build(int l, int r, int f) {
    st = f;
    nth_element(p + l, p + m, p + r + 1, [] (point x, point y) {
        return x.d[st] < y.d[st];
    });
    tree[m].d[0] = p[m].d[0], tree[m].d[1] = p[m].d[1];
    tree[m].maxn[0] = tree[m].minn[0] = p[m].d[0];
    tree[m].maxn[1] = tree[m].minn[1] = p[m].d[1];
    if (l < m) tree[m].l = build(l, m - 1, f ^ 1);
    if (r > m) tree[m].r = build(m + 1, r, f ^ 1);
    push_up(m);
    return m;
} 

double ans = 2e18;

double work(point x, int id) {
    double res = 2e18;
    if (x.d[0] >= tree[id].minn[0] && x.d[1] >= tree[id].minn[1] && x.d[0] <= tree[id].maxn[0] && x.d[1] <= tree[id].maxn[1]) {
        return 0.0;
    }
    if (x.d[0] < tree[id].minn[0] || x.d[0] > tree[id].maxn[0]) {
        res = min(fabs(tree[id].minn[0] - x.d[0]), fabs(tree[id].maxn[0] - x.d[0]));
    }
    if (x.d[1] < tree[id].minn[1] || x.d[1] > tree[id].maxn[1]) {
        res = min(res, fabs(tree[id].maxn[1] - x.d[1]));
        res = min(res, fabs(tree[id].minn[1] - x.d[1]));
    }
    return res;
    
}

int f = 0;

void query(int l, int r, point x) {
    double res = work(x, m);
    //cout << "res = " << res << endl;
    
    if (res < ans) {
        double cnt = dist(x, point(tree[m].d[0], tree[m].d[1]));
    //    cout << "cnt " << cnt << endl;
        if (cnt < ans) {
            if (cnt == 0) {
                if (f == 0) {
                    f = 1;
                } else {
                    ans = cnt;
                }
            } else {
                ans = cnt;
            }
        }
        if (l < m) query(l, m - 1, x);
        if (r > m) query(m + 1, r, x);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &p[i].d[0], &p[i].d[1]);
    }
    int rt = build(1, n, 0);
    for (int i = 1; i <= n; i++) {
        f = 0;
        query(1, n, p[i]);
    }
 //   double cnt = sqrt(ans);
    printf("%.4lf\n", ans);
}