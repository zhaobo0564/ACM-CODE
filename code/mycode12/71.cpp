#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int fa[N], n, a[N], b[N], c[N];

vector<int> g;

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        g.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
            g.push_back(a[i]);
            g.push_back(b[i]);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for (int i = 1; i <= g.size(); i++) {
            fa[i] = fa[i] = i;
        }
        int f = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = get_id(a[i]);
            b[i] = get_id(b[i]);
            if (c[i] == 1) {
                int fx = find(a[i]);
                int fy = find(b[i]);
                if (fx != fy) {
                    fa[fx] = fy;
                } 
            }
        }
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {
                int fx = find(a[i]);
                int fy = find(b[i]);
                if (fx == fy) {
                    f = 1;
                    break;
                }
            }
        }
        if (f) {
            cout << "NO\n";
        }  else {
            cout << "YES\n";
        }
    }
}