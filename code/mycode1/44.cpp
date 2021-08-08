#include<bits/stdc++.h>
using namespace std;

const int N = 5007;

vector<int>g[N];

int dfn[N], flow[N], cnt, vis[N], in[N];
stack<int>q;

int cat[N], top = 1;

int n, m, s;

void tarjan(int u){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(int to: g[u]){
        if(!dfn[to]){
            tarjan(to);
            flow[u] = min(flow[u], flow[to]);
        }else if(vis[to]){
            flow[u] = min(flow[u], dfn[to]);
        }
    }


    if(flow[u] == dfn[u]){
        while(1){

            int now = q.top();
            q.pop();
            vis[now] = 0;
            cat[now] = top;
            if(now == u)break;
        }
        top++;
    }
}

void dfs(int u){

    vis[u] = 1;
    for(int to: g[u]){
        if(vis[to])continue;
        dfs(to);
    }
  
}

vector<pair<int, int> > p;

int main(){
    scanf("%d %d %d",&n, &m, &s);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d",&u, &v);
        g[u].push_back(v);
        p.push_back({u, v});

    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)g[i].clear();
    for(int i = 0; i < m; i++){
        if(cat[p[i].first] != cat[p[i].second]){
            g[cat[p[i].first]].push_back(cat[p[i].second]);
            in[cat[p[i].second]]++;
        }
    }
    dfs(cat[s]);
    for(int i = 1; i < top; i++){
        if(!vis[i] && !in[i]){
            ans++;
        }
    }
    
    printf("%d\n", ans);



}