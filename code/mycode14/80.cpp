#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, m, top = 1;
ll G, S;
struct edge {
    int u, v;
    ll g, s;
}e[N];

int fa[N];

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}


int main() {
    cin >> n >> m >> G >> S;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ll g, s; cin >> g >> s;
        e[i] = {u, v, g, s};
    }

    sort(e + 1, e + m + 1, [](auto x, auto y) {
        return x.g < y.g; 
    });
    int cnt = 0;
    ll gg = 0, ss = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx == fy) continue;
        fa[fx] = fy;
        gg = max(gg, e[i].g);
        ss = max(ss, e[i].s);
    }
    ll ans = gg * G + ss * S;
    sort(e + 1, e + m + 1, [](auto x, auto y) {
        return x.s < y.s; 
    });
    gg = 0, ss = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
     for (int i = 1; i <= m; i++) {
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx == fy) continue;
        fa[fx] = fy;
        gg = max(gg, e[i].g);
        ss = max(ss, e[i].s);
    }
    ans = min(ans, gg * G + ss * S);
    cout << ans << endl;



    
    
}