#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N], n, k;

vector<int> g[N];

vector<int> ans[N];

int vis[N], top = 0;

void dfs(int u) {
    vis[u] = 1;
    ans[top].push_back(u);
    for (int to: g[u]) {
        dfs(to);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] != i) {
            g[a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            top++;
            dfs(i);
        }
    }
    int f = 0;
    for (int i = 1; i <= top; i++) {
        int cnt = (int)ans[i].size();
        cnt = k % cnt;
        
    }
}