#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

vector<int>g[N];
int t, n, x;
int ans = 0;

void dfs(int u, int fa){
  
    for(int to: g[u]){
        if(to == fa)continue;
        if(g[to].size() > 2){
            ans += g[to].size() - 2;
        }
        dfs(to, u);
        
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &x);
        ans = 0;
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(g[x].size() == 1){
            puts("Ayush");
        }else{
            dfs(x, 0);
            ans += g[x].size();
           // cout << ans << endl;
           // cout << g[x].size() << endl;
            if(ans % 2 == 0){
                int cnt = ans / 2;
                if(cnt % 2 == 0){
                    puts("Ayush");
                }else{
                    puts("Ashish");
                }
            }else{
                int cnt =ans / 2;
                if(cnt % 2 == 0){
                    puts("Ayush");
                }else{
                    puts("Ashish");
                }
            }
        }
    }
}