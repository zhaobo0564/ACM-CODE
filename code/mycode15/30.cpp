#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int a[N], b[N], n, x, y;

struct node {
    int v, pos;
};

vector<node> g;

bool cmp(node x, node y) {
    if (x.v == y.v) {
        return b[x.pos] - a[x.pos] > b[y.pos] - a[y.pos];
    }
    return x.v < y.v;
}

int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g.push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    sort(g.begin(), g.end(), cmp);
    for (int i = 0; i < x; i++) {
        if (g[i].v < y) {
            g[i].v = y;
        }
    }
    sort(g.begin(), g.end(), [](node x, node y) {
        return x.v < y.v;
    });
    int maxn = 0;
    sort(b + 1, b + n + 1);
    for (int i = 0; i < g.size(); i++) {
        if (g[i].v < b[i + 1]) {
            maxn = max(maxn, b[i + 1] - g[i].v);
        }
    }
    cout << maxn << endl;
    return 0;


}