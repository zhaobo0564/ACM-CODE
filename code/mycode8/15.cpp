#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;

struct segment {
    double l, r;
    int cover;
} tree[4 * N];

struct line {
    double h, x, y;
    int c;
}q[N];

vector<double> g;

bool cmp(line x, line y) {
    return x.h < y.h;
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    tree[node].l = g[l - 1];
    tree[node].r = g[r - 1];
    if (r - l == 1) return;
    build(l, m, lson);
    build(m, r, rson);
}

void update(int v, double ql, double qr, int node) {
    if (tree[node].l > qr || tree[node].r < ql) return;
    if (tree[node].l >= ql && tree[node].r <= qr) {
        tree[node].cover += v;
        return;
    }
    update(v, ql, qr, lson);
    update(v, ql, qr, rson);
}

double query(int node) {
    if (tree[node].l == 0 && tree[node].r == 0) {
        return 0;
    }
    
    if (tree[node].cover > 0) {
        return tree[node].r - tree[node].l;
    }

    return query(lson) + query(rson);
    
}

int main() {
    int n;
    int ca = 1;
    while (~scanf("%d", &n) && n) {
        int top = 1;
        memset(tree, 0, sizeof(tree));
        g.clear();
        for (int i = 1; i <= n; i++) {
            double x[2], y[2];
            scanf("%lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1]);
            q[top].x = x[0], q[top].y = x[1], q[top].h = y[0], q[top].c = 1;
            q[++top].x = x[0], q[top].y = x[1], q[top].h = y[1], q[top].c = -1;
            top++;
            g.push_back(x[0]);
            g.push_back(x[1]);
        }

        sort(q + 1, q + top, cmp);
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        build(1, g.size(), 1);
        double ans = 0.0;
        for (int i = 1; i < top - 1; i++) {
        //    cout << "l " << q[i].x << " r = " << q[i].y << endl;
            update(q[i].c, q[i].x, q[i].y, 1);
            double w = query(1);
           // cout << "w " << w << endl;
            ans += w * (q[i + 1].h - q[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ca++, ans);


        
    }
}