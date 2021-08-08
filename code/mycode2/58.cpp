#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int>g[N];

int n, m;
int vis[N], f = 0, s[N];
void dfs(int u){
    vis[u] = 1;
    for(int to: g[u]){
        if(!vis[to]){
            s[to] = -s[u];
            dfs(to);
        }else{
            if(s[to] == s[u]){

                f = 1;
            }
        }
    }
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            ans++;
            s[i] = 1;
            dfs(i);
        }
    }
    cout << ans - f << endl;
}