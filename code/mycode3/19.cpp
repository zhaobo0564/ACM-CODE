#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int head[N], n, c[N];

struct edg{
    int to, w;
    int next;
}e[ 2 * N];
int top = 1;

void add(int u, int v, int cost){
    e[top].to = v;
    e[top].w = cost;
    e[top].next = head[u];
    head[u] = top++;
}

int dp[N];
int ans = INT_MIN;

void dfs(int u, int fa){
    int f = 0;
    dp[u] = c[u];
    for(int i = head[u]; i; i = e[i].next){
        int to = e[i].to;
        int cost = e[i].w;
        if(to == fa)continue; 
        f = 1;
        dfs(to, u);
        //cout << "to " << to << " cost" << cost << endl;
        ans = max(ans, dp[u]  + dp[to] + cost);
       // cout << "ans = " << ans << endl;
        dp[u] = max(dp[u], dp[to] + cost);

    }
    //if(f == 0)dp[u][1] = c[u];
}
void init(){
    top = 1;
    ans = INT_MIN;
    memset(head, 0, sizeof(head));
 

}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &n);
        for(int i = 2; i <= n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            add(i, a, b);
            add(a, i, b);
        
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &c[i]);
        }
        dfs(1, 0);
        printf("%d\n", ans);

    }
}


