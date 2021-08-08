#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
vector<int> g[N];

int dp[N], k;
vector<int> v;

void dfs(int u) {
    for (int to: g[u]) {
        dfs(to);
        dp[u] = max(dp[u], dp[to] + 1);
    }
}

bool cmp(int a, int b) {
    return dp[a] < dp[b];
}

int cnt;

void work(int u) {
    v.push_back(u);
    if (cnt == 0) return;
    sort(g[u].begin(), g[u].end(), cmp);
    int f = 0;
    for (int to: g[u]) {
        if (cnt > 0) {
            f = 1;
            cnt--;
            work(to);
            v.push_back(u);
        }
        
    }
} 



void gao(int u, int all) {
    v.push_back(u);
    if (all == 0) return;
    sort(g[u].begin(), g[u].end(), cmp);
    int maxn = dp[g[u][g[u].size() - 1]];
    if (maxn >= all) {
        gao(g[u][g[u].size() - 1], all - 1);
    } else {
        cnt = all - maxn;
        for (int i = 0; i < g[u].size() - 1; i++) {
            if (cnt == 0) break;
            cnt--;
            work(g[u][i]);
            v.push_back(u);
        }

        gao(g[u][g[u].size() - 1], cnt + maxn - 1); 
        
    }
  
    
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        v.clear();
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            int x; scanf("%d", &x);
            g[x].push_back(i);
        }
        dfs(1);
        gao(1, k - 1);
        cout << v.size() - 1 << endl;
        for (int i: v) {
            printf("%d ", i);
        }
        puts("");
    }
}
