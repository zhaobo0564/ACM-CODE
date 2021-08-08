#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, t, k;
vector<int> g[N];
int sizes[N];

void dfs(int u, int fa){
    sizes[u] = 1;
    for(int i: g[u]){
        if(i == fa)continue;
        dfs(i, u);
        sizes[u] += sizes[i];
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        memset(sizes, 0, sizeof(sizes));
        for(int i = 1; i < n; i++){
            int u,v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        dfs(1, 0);
        for(int i = 1; i <= n; i++){
            if(sizes[i] >= k && n - sizes[i] >= k)
                ans++;
        }
        printf("%d\n", ans );
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }


    }
}