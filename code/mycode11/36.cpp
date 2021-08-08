#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<int> g[N];

int n;

int sz[N], son[N], father[N][22], deep[N];
vector<int> v, v1;

void dfs(int u, int fa) {
    father[u][0] = fa;
    for (int i = 1; i <= 20; i++) {
        father[u][i] = father[father[u][i - 1]][i - 1]; 
    }
    deep[u] = deep[fa] + 1;
    int f = 0;
    for (int to: g[u]) {
        if (to == fa) continue;
        f = 1;
        dfs(to, u);
        sz[u] += sz[to];
    }
    if (f == 0) {
        son[u] = 1;
        v1.push_back(u);
    }
}

int get_lca(int x, int y) {
    
    if (deep[y] > deep[x]) swap(x, y);
    int d = deep[x] - deep[y];
    for (int i = 0; i <= 20; i++) {
        if (d & 1) {
            x = father[x][i];
        }
        d = d / 2;
    }
    if (x == y) return x;
  
    for (int i = 20; i >= 0; i--) {
        if (father[x][i] != father[y][i]) {
       
            x = father[x][i];
            y = father[y][i];
        }
    }
    
    return father[x][0];
}

int dp[N];

int ok = 0;

void dfs1(int u) {
    int f = 0;
    if (father[u][0] && dp[u] == dp[father[u][0]]) {
        f++;
    }
    for (int to: g[u]) {
        if (to == father[u][0]) {
            continue;
        }
        if (dp[to] == dp[u]) {
            f++;
        }
        dfs1(to);
    }
    if (f != 1) {
        ok = 1;
    }
}

void solve() {
    for (int i: v) {
        int now = i;
      //  cout << dp[now] << endl;
        while (now) {
            if (dp[father[now][0]] >= 0) break;
            dp[father[now][0]] = dp[now];
            if (dp[father[now][1]] >= 0) break;
            dp[father[now][1]] = dp[now] ^ 1;
            now = father[now][1];
            
            
        }
    }
}

bool cmp(int x, int y) {
    if (deep[x] % 2) {
        return false;
    }
    return true;
}


int main() {
    cin >> n;
    if (n == 1) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (son[i]) {
            if (sz[father[i][0]] > 2) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
   // sort(v.begin(), v.end(), cmp);
  //  cout << v[0] << endl;
    for (int i: v1) {
        if (deep[i] % 2 == 0) {
            v.push_back(i);
        }
    }
    for (int i: v1) {
        if (deep[i] % 2) {
            v.push_back(i);
        }
    }
   //cout << v[0] << endl;
    dp[v[0]] = 1;
    for (int i = 1; i < v.size(); i++) {
        int lca = get_lca(v[i], v[i - 1]);

        int d = deep[v[i]] - deep[lca] + 1;
        int cnt = d / 2;
        int d1 = deep[v[i - 1]] - deep[lca] + 1;
        int cnt1 = d1 / 2;
        if (d1 % 2) {
            cnt1++;
        }
        int now = 0;
        if (cnt1 % 2) {
            now = dp[v[i - 1]];
        } else {
            now = dp[v[i - 1]] ^ 1;
        }
        if (d % 2) {
            cnt++;
        }
        if (cnt % 2) { // ±¾Éí
            dp[v[i]] = now;
        } else {
            dp[v[i]] = now ^ 1;
        }
    }

    solve();
    dfs1(1);
    if (ok == 1) {
        puts("-1");
    } else {
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 1) {
                cout  << "R";
            } else {
                cout << "B";
            }
            
        }
        cout << endl;
    }
    
                                                                           

}

