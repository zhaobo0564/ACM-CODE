#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
typedef long long ll;

vector<int> g[N];
int vis[N];
int ans = 0;
vector<int> v;

void dfs(int u, int deep, int s) {
    
    if (deep == 3) {
        ans++;
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        if (vis[g[u][i]] == 0) {
            vis[g[u][i]] = 1;
            dfs(g[u][i], deep + 1, s);
            vis[g[u][i]] = 0;
        } else if (deep + 1 == 3 && g[u][i] == s) {
            dfs(g[u][i], deep + 1, s);
        } 
       
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dfs(i, 0, i);
        vis[i] = 0;
    }
    cout << ans << endl;



}