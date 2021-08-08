#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7;

struct edge {
    int u, v, w;
} e[ 2 * N];

int fa[N];

int find(int x) {
    if (fa[x] != x) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

bool cmp(edge x, edge y) {
    return x.w > y.w;
}

int n, m;

bool judge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return true;
    return false;
}

int main() {
    int s, t;
    ios::sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1, cmp);
    int l = 0, pos;
    for (int i = 1; i <= m; i++) {
        if (judge(s, t)) {
            break;
        }
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx != fy) {
            fa[fx] = fy;
        }
        l = e[i].w;
        pos = i;
    }
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int r = 0;
    for (int i = pos; i; i--) {
        if (judge(s, t)) {
            break;
        }
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx != fy) {
            fa[fx] = fy;
        }
        r = e[i].w;
    }
    printf("%d %d\n", l, r);

}