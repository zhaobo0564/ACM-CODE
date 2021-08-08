#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int  fa[N];

struct node {
    int a, b, c;
}p[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}
int n; 
void solve() {
    for (int i = 1; i <= n; i++) {
        int u = get_id(p[i].a);
        int v = get_id(p[i].b);
        if (p[i].c == 1) {
            int fx = find(u);
            int fy = find(v);
            if (fx != fy) {
                fa[fx] = fy;
            }
        } else {
            int fx = find(u);
            int fy = find(v);
            if (fx == fy) {
                puts("NO");
                return;
            }
        }
    }

    puts("YES");
}
bool cmp(node x, node y) {
    return x.c > y.c;
}

int main() {

    int t; cin >> t;
    while (t--) {
        cin >> n;
        g.clear();
        for (int i = 1; i <= n; i++) {
            cin >> p[i].a >> p[i].b >> p[i].c;
            g.push_back(p[i].a);
            g.push_back(p[i].b);
            fa[i] = i;
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= 2 * n + 1; i++) {
            fa[i] = i;
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        solve();
        
    }
    return 0;
}