#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
int ans[N], n, m;

vector<pair<int, int> >g[N];

void dfs(int u, int fa) {
    for (auto it: g[u]) {
        int to = it.first;
        int cost = it.second;
        if (to == fa) continue;
        if (ans[to] == 0 && ans[u] == 0) {
            ans[u] = cost;
            while (1) {
                ans[to] = rand() % n + 1;
                if (ans[to] != cost) break;
            }
            dfs(to, u);
        } else if (ans[u] == cost && ans[to] == 0) {
            while (1) {
                ans[to] = rand() % n + 1;
                if (ans[to] != cost) break;
            }
            dfs(to, u);
        } else if(ans[u] && ans[to] == 0) {
            ans[to] = cost;
            dfs(to, u);
        }
    }
}



int main() {
    srand(time(0));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    
    
}