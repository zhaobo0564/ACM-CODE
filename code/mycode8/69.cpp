#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int fa[N], n, q, a[N], sz[N];

map<int, int> v[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        v[i][a[i]]++;
    }

    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            int fx = find(l);
            int fy = find(r);
            if (fx == fy) continue;
            if (sz[fx] > sz[fy]) swap(fx, fy);
       
            for (auto i: v[fx]) {
                v[fy][i.first] += v[fx][i.first];
              
            }
            sz[fy] += sz[fx];
            fa[fx] = fa[fy];
        } else {
            int fx = find(l);
            printf("%d\n", v[fx][r]);
        }
    }

    
}