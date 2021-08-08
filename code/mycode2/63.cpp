#include<bits/stdc++.h>
using namespace std;
const int N = 200007;
vector<int>g[N];
int fa[N];

int n;

void dfs(int u, int f){
    fa[u] = f;
    for(int to: g[u]){
        if(to == f)continue;
        dfs(to, u);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        ans = 0;
        for(int to:g[i]){
            if(to == fa[i])continue;
            ans += g[to].size() - 1;
        }
        if(fa[i])
            ans += g[fa[i]].size() - 1;

        printf("%d\n", ans);
    }

}