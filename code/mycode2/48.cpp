#include<bits/stdc++.h>
using namespace std;
const int N = 1e5  + 7;

vector<int>g[N];

int dfn[N], flow[N], cnt, vis[N];
stack<int>q;
int cn[N];

int ans = 0, Ans = 0;
int n, m, s;

void tarjan(int u, int fa){
    dfn[u] = flow[u] = ++cnt;
    vis[u] = 1;
    q.push(u);
    for(int to: g[u]){
        if(!dfn[to]){
            tarjan(to, u);
            flow[u] = min(flow[u], flow[to]);
        }else if(vis[to] && to != fa){
            flow[u] = min(flow[u], dfn[to]);
        }
    }


    if(flow[u] == dfn[u]){
        vector<int>p;
        cout << flow[u] << endl;
        while(1){
            int now = q.top();
            q.pop();
            cn[now] = 1;
            vis[now] = 0;  
            p.push_back(now);
            cout << now << " ";
            if(now == u)break;
        }
        cout << endl;
        cout << "sad " << flow[5] << endl;
        if(p.size() > 1){
            for(int i : p){
               for(int j : g[i]){
                   if(cn[j]){
                       ans++;
                   }
               }
               cn[i] = 0;
            }
        }else{
            cn[p[0]] = 0;
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
    tarjan(1, 0);
    printf("%d\n", ans );
}

