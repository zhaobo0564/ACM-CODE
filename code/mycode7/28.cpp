#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
vector<int> g[N];
ll s[N], n, a[N], sum = 0, ok = 0, vis[N], fa[N];

void dfs(int u, int f, int deep) {
    fa[u] = f;
    if (f && deep % 2) {
        ll cnt = s[u] - s[fa[f]];
        if (cnt < 0) ok = 1;
            a[u] = cnt;
            a[f] = 0;
    }
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u, deep + 1);

    }
  
}

ll son[N];

void dfs1(int u, int f, int deep) {
    son[u] = 1e15;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs1(to, u, deep + 1);
        if (deep % 2 == 0) {
           son[u] = min(son[u], a[to]); 
        }
        
        
    } 

    if (deep % 2 == 0 && g[u].size() > 1) {
        for (int to: g[u]) {
            if (to == f) continue;
            a[to] -= son[u];
            a[u] = son[u];
        }
        
    }
  
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    a[1] = s[1];
    dfs(1, 0, 1);
   
    dfs1(1, 0, 1);
    
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        
    }
  
    if (ok) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
    }
   

}