#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector<int> g[N], pos[N], cn[N];

int n, m, ans[N];

struct node {
    int id, sz, x;
}p[N];

bool cmp(node x, node y) {
    return x.sz < y.sz;
}

int vis[N], color[N], cat[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= m + 1; i++) {
        g[i].clear();
        cn[i].clear();
        color[i] = 0;
        vis[i] = 0;
        cat[i] = 0;
        ans[i] = 0;
    }
    for (int i = 0; i <= n + 1; i++) {
        pos[i].clear();
        color[i] = 0;
        vis[i] = 0;
        cat[i] = 0;
        ans[i] = 0;
        
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j++) {
            int v; cin >> v;
            g[i].push_back(v);
            pos[v].push_back(i);
            vis[v]++;
        }
    }
    int base = m / 2;
    if (m % 2) base++;
    for (int i = 1; i <= n; i++) {
        if (vis[i] <= base) {
          
            for (int j: pos[i]) {
                if (color[j] == 0) {
                    ans[j] = i;
                
                }
                color[j] = 1;
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) {
            f = 1;
        }
    }
    if (f == 0) {
        cout << "YES\n";
        for (int i = 1; i <= m; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    } 
    int top = 1;
    for (int i = 1; i <= m; i++) {
        if (color[i] == 0) {
           
            for (int j: g[i]) {
                cn[top].push_back(j);
            }
            p[top].id = top;
            p[top].sz = cn[top].size();
            p[top].x = i;
            top++;
        }
    }
    sort(p + 1, p + top, cmp);
    for (int i = 1; i < top; i++) {
        int f = 0;
        for (int j: cn[p[i].id]) {
            if (cat[j] < base) {
                f = 1;
                cat[j]++;
                ans[p[i].x] = j;
                break;
            }
        }
        if (f == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;



}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}