#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct EDGE {
    int to, w, next;
} edge[1000000];
int cnt;
int head[2000];
int deep[2000];
int n, m;
int d[55], a[105], b[105];

vector<int> g[100];
 
void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i <= n; i++)g[i].clear();
}
 
void addedge(int u, int v, int w) {
    edge[cnt].to=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt++;
    edge[cnt].to=u; edge[cnt].w=0; edge[cnt].next=head[v]; head[v]=cnt++;
}
 
int bfs(int s, int t) {
    queue<int> q;
    memset(deep, 0, sizeof(deep));
    q.push(s);
    deep[s] = 1;
    int top;
    while(!q.empty()) {
        top = q.front();
        q.pop();
        for(int i = head[top];i+1; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].w;
            if(!deep[v]&&w) {
                deep[v] = deep[top]+1;
                q.push(v);
            }
        }
    }
    return deep[t];
}
 
int dfs(int s, int t, int inflow) {
    if(s==t) return inflow;
    int acflow=0;
    for(int i=head[s]; i+1; i=edge[i].next) {
        if(edge[i].w && deep[s]+1 == deep[edge[i].to]) {
            int x = dfs(edge[i].to,t,min(inflow, edge[i].w));
            if(x>0) {
                acflow+=x; inflow-=x;edge[i].w -= x; edge[i^1].w += x;
                if(!inflow) break;
            }
        }
    }
    if(!acflow) deep[s] = -2;
    return acflow;
}
 
int dinic(int s,int t) {
    int f = 0;
    while(bfs(s,t)) f += dfs(s,t,INF);
    return f;
}
 

 
int main() {
    while(~scanf("%d %d", &n, &m)) {
        init();
        int sum = 0;
        for(int i = 1;i <= n; i++) {
            scanf("%d", &d[i]);
            sum += d[i];
            addedge(0, i, d[i]);
        }
         
        int num = n;
        for(int i = 1;i <= m; i++) {
            scanf("%d %d", &a[i], &b[i]);
            // addedge(a[i], ++num, 1);
            // addedge(b[i], num, 1);
            g[a[i]].push_back( b[i]);
            g[b[i]].push_back(a[i]);

        }
        for (int i = 1; i <= n; i++) {
            //if(g[i].size() == 0)continue;
            for (int j = 0; j < g[i].size(); j++) {
                addedge(i, num + g[i][j], 1);
            }
        }
        num += n;
        int fin = num+1;
        for(int i = n+1;i <= num; i++) {
            addedge(i, fin, d[i - n]);
        }
        printf("%s\n", dinic(0, fin)==sum?"Yes":"No");
    }
}