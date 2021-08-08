#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;

int  fa[N], n, q , cnt[N], son[N], brother[N];

vector<int>g[N];





void dfs(int u, int f){
    fa[u] = f;
    for(int j : g[u]){
        if(j == f) continue;
        dfs(j, u);
    }
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    while(q--){
        int c; scanf("%d", &c);
        int ans = cnt[fa[c]] + cnt[fa[fa[c]]] + son[c] + brother[fa[c]];
        cnt[c]++;
        if(fa[c])son[fa[c]]++;
        if(fa[fa[c]])son[fa[fa[c]]]++;
        brother[fa[c]]++;
        
        printf("%d\n", ans + 1);

    }

   
        
        
        

    }









