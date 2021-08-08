#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, m, a, b, c;
int vis[N], dist1[N], dist2[N], dist3[N];
long long p[N];
vector<int> g[N];
queue<int>q;

void bfs(int s, int dist[]){
 
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
        dist[i] = INT_MAX;
    }
    q.push(s);
    dist[s] = 0;
    while(q.size()){
        int cd = q.front();
        q.pop();
        if(vis[cd])continue;
        vis[cd] = 1;
        for(int to: g[cd]){
            if(dist[to] > dist[cd] + 1){
                dist[to] = dist[cd] + 1;
                q.push(to);
            }
        }
    }

}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
        for(int i = 1; i <= m; i++){
            scanf("%lld", &p[i]);
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        sort(p + 1, p + m + 1);
        for(int i = 1; i <= m; i++){
            p[i] = p[i] + p[i - 1];
        }

        bfs(a, dist1);
        bfs(b, dist2);
        bfs(c, dist3);
        long long ans = LLONG_MAX;
        for(int i = 1; i <= n; i++){
            int cnt = dist2[i];
            int cnt1 = dist1[i] + dist3[i];
            if(cnt + cnt1 > m)continue;
            ans = min(ans, p[cnt] + p[cnt + cnt1]);
        }
        printf("%lld\n",ans);
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
    

    }

}