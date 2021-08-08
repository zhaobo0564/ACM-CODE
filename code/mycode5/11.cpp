#include<bits/stdc++.h>

using namespace std;
const int N = 200007;

vector<pair<int, char> > g[N];

int n, m, dist[N];

queue<pair<int, int> > q;

void bfs(){
    q.push({n, 0});
    memset(dist, -1, sizeof(dist));
    while (q.size()){
        auto cd = q.front();
        q.pop();
        if (dist[cd.first] != -1) continue;
        dist[cd.first] = cd.second;
        for (auto it: g[cd.first]) {
            int to = it.first;
            q.push({to, cd.second + 1});
        }
    }
}

int vis[N];
vector<int>Q;
vector<int> ans;
int fa[N];

void path(int x){
    if(x == 0) return;
    path(fa[x]);
    printf("%d ", x);
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        char w;
        scanf("%d %d %c", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    bfs();
    Q.push_back(1);
    for (int i = 1; i <= dist[1]; i++) {
        int minn = 1000;
        vector<int> v;
        for(int cd: Q) {
            for (auto it: g[cd]){
                int to = it.first;
                int cost = (int)it.second;
                if (dist[to] + 1 == dist[cd])
                    minn = min(minn, cost);
            }
        }
        for(int cd: Q){
            for (auto it: g[cd]){
                int to = it.first;
                int cost = (int)it.second;
                if (dist[to] + 1 == dist[cd]) {
                    if (cost == minn && vis[to] == 0) {
                        v.push_back(to);
                        fa[to] = cd;
                        vis[to] = 1;
                    }
                }
            }
        }

        ans.push_back(minn);
        Q.clear();
        for(int j: v){
            Q.push_back(j);
        }

    }

    printf("%d\n", (int)ans.size());
    path(n);
    puts("");
    for(int i: ans){
        printf("%c", (char)i);
    }
    puts("");
    
}