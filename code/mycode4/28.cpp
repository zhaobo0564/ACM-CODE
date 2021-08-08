#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int head[N], top = 1, dp[N][4], a[N], father[N];

struct edge{
    int u, cost, nxt;
}e[2 * N];

void add_edge(int u, int v, int w){
    e[top].u = v;
    e[top].cost = w;
    e[top].nxt = head[u];
    head[u] = top++;
}

void dfs(int u, int fa){
    dp[u][0] = a[u];
    dp[u][1] = a[u];
    father[u] = fa;
    int ans = 0;
    int w = 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].u;
        int cost = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        
        dp[u][0] = max(dp[u][0], dp[to][0] + cost + a[u]);
        dp[u][0] = max(dp[u][0], dp[u][1] + dp[to][0] + cost);
        dp[u][1] = max(dp[u][1], dp[to][1] + 2 * cost + a[u]);
    }
}

void dfs1(int u, int fa){
    if(fa){
        dp[u][2] = dp[father[u]][2];
        dp[u][3] = dp[father[u]][3];
        int w = 0;
        int back = 0, back1 = 0;
        for(int i = head[fa]; i; i = e[i].nxt){
            int to = e[i].u;
            int cost = e[i].cost;
            if(to == father[father[u]])continue;
            else if(to == u){
                w = cost;
            }else{
                // if(u == 4){
                //     cout <<"aa " << dp[to][0] << " " << cost << " " << a[father[u]] << endl;
                //    // cout << to <<" " << back1<< endl;
                // }
                
                dp[u][2] = max(dp[u][2], dp[to][1] + 2 * cost  + dp[u][2]);
               // dp[u][2] = max(dp[u][2], back1 + cost);
                dp[u][2] = max(dp[u][2], dp[to][0] + cost + a[father[u]]);
                dp[u][3] = max(dp[u][3], dp[to][1] + 2 * cost  + dp[u][3]);
                dp[u][3] = max(dp[u][3], dp[to][1] + 2 * cost + a[father[u]]); 
               // dp[u][3] = max(back + 2 * cost , dp[u][3]);
                back1 = max(back1, back + dp[to][0] + cost);
                back = max(dp[to][1] + 2 * cost + a[father[u]], back);
            }
        }
        dp[u][2] = max(dp[u][2], back1);
        dp[u][2] = max(dp[u][2] + w + a[u], a[u]);
        dp[u][3] = max(dp[u][3] + 2 * w + a[u], a[u]);
    }else{
        dp[u][2] = a[u];
        dp[u][3] = a[u];
    }
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].u;
        if(to == fa)continue;
        else{
            dfs1(to, u);
        }
    }
}


int main(){
    int t, n; scanf("%d", &t);
    int cnt = 1;
    while(t--){
        top = 1;
        scanf("%d", &n);
        memset(head,0,sizeof(head));
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, -w);
            add_edge(v, u, -w);
        }
         dfs(1, 0);
         dfs1(1, 0);
        printf("Case #%d:\n", cnt++);
        for(int i = 1; i <= n; i++){
            int ans = max(dp[i][0], dp[i][2]);
            ans = max(ans, dp[i][3] + dp[i][0] - a[i]);
            ans = max(ans, dp[i][1] + dp[i][2] - a[i]);
            printf("%d\n", ans);
            //  cout << dp[i][0] << " " << dp[i][1] << endl;
            //  cout << dp[i][2] << " " << dp[i][3] << endl << endl;
        }
        
    }
}

