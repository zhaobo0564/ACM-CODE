#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a[N], deep[N], dep[N];
vector<int> g[N];

int Fa[N][21], ans;

void dfs(int u, int fa, int deep) {
    ans = max(ans, deep ^ a[u]);
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u, deep ^ a[u]);
    }
}



int main() {
    freopen("A.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    scanf("%d", &n);
    //cout << "N = " << n << endl;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
    }
   // cout << maxn << endl;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    ans = 0;
   
   
    for (int i = 1; i <= n / 100; i++) {
        dfs(i, 0, 0);    
        if (ans == 4194303) {
            cout << "i = " << i << endl;
        }
     
    }
    cout << ans << endl;
}


