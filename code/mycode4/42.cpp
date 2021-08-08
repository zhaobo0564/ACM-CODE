#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, a[N], head[N], top = 1, n;
int dp[N][3], id[N], ans[N];

struct edge{
    int to, nxt, cost;
}e[2 * N];

void add_edge(int u, int v, int w){
    e[top].to = v;
    e[top].cost = w;
    e[top].nxt = head[u];
    head[u] = top++;
}


// a[u]表示节点为u的权值.
void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = dp[u][2] = a[u];
    // 求回来的最大收益
    for(int i = head[u]; i; i = e[i].nxt){      // 建议用链式前向星存图
        int to = e[i].to;
        int cost = e[i].cost;
        if(to == fa)continue;
        dfs(to, u);
        if(dp[to][2] + 2 * cost > 0){         // 存的就是负边所以直接加
            dp[u][2] += dp[to][2] + 2 * cost;   // 由于 dp[u][2]求的是回来的最大值， 当回来收益大于0时我贪心加在一起
        }
    }
    id[u] = u;
    // 求不回来的最大与次大收益
    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        if(to == fa) continue;
        int now = dp[u][2] - max(0, dp[to][2] + 2 * cost) + max(0, dp[to][0] + cost);
        if(dp[u][0] < now ){
            dp[u][1] = dp[u][0];        // 计算次大值
            dp[u][0] = now ;  // 计算最大值
            id[u] = to;                     // 最大值第一步走的儿子节点
        }else if(dp[u][1] < now ){
            dp[u][1] = now ;      // 更新次大值
        }
    }
}

void dfs1(int u, int fa, int noback, int back){
    ans[u] = max(dp[u][0] + back, dp[u][2] + noback); // 只会有从父亲回来走儿子或者从儿子回来走父亲， 其它情况都不是最优的。

    for(int i = head[u]; i; i = e[i].nxt){
        int to = e[i].to;
        int cost = e[i].cost;
        if(fa == to) continue;
        int now_no_back, now_back; // 分别表示父亲节点 不回来/回来且不经过to节点的最大值
        if(to == id[u]){ // 如果成立,表示当前节点包含了最大值如果选最大值会重复计算， 所以选次大值
            now_no_back = dp[u][1] - max(0, dp[to][2] + 2 * cost);
        }else{
            now_no_back = dp[u][0] - max(0, dp[to][2] + 2 * cost);
        }
        now_back = dp[u][2] - max(0, dp[to][2] + 2 * cost);
        now_no_back = max(now_no_back, back + now_no_back) + cost;
        now_no_back = max(now_no_back, now_back + noback + cost);
        now_back = max(now_back + 2 * cost, now_back + back + 2 * cost);
        dfs1(to, u, max(0, now_no_back), max(0, now_back));
    


    }
}


int main(){
    scanf("%d", &t);
    int ca = 1;
    while(t--){
        top = 1;
        scanf("%d", &n);
        for(int i = 0; i <= n + 1; i++){
            head[i] = 0;
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
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
        dfs1(1, 0, 0, 0);
        printf("Case #%d:\n", ca++);
        for(int i = 1; i <= n; i++){
            printf("%d\n", ans[i]);
        }
        
    }
}