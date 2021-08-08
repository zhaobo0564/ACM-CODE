#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int t, n, m, s, vis[N][N];
vector<int> g[N];
vector<int> v;
int ans = 0;



void dfs(int u, int p){
    if(p == s){
        ans++;
        return;
    }
    for(int i: g[u]){
        int f = 0;
        for(int j: v){
            if(!vis[min(i, j)][max(i, j)]){
                f = 1;
                break;
            }
        }
        if(!f){
            v.push_back(i);
            dfs(i, p + 1);
            v.pop_back();
        }
    }
}

int main(){
   scanf("%d", &t);
   while(t--){
       ans = 0;
        scanf("%d %d %d", &n, &m, &s);
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            vis[min(u, v)][max(u, v)] = 1;
            g[min(u, v)].push_back(max(u, v));
        }
        for(int i = 1; i <= n; i++){
            if(g[i].size() + 1 >= s){
                v.push_back(i);
                dfs(i, 1);
                v.pop_back();
            }
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                vis[i][j] = 0;
            }
            g[i].clear();
        }
   }
   
   
}
