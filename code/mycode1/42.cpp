#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

typedef long long ll;

vector<pair<ll, ll> >g[N];
vector<int> G[N];

struct edge{
    int u, v, w;
}p[N];

int n, m, f[N];
ll dist[N], vis[N], dist1[N];

struct node{
    int v;
    long long w;
    bool operator <(const node a)const{
        return w > a.w;
    }

};

void dj(int s){
    priority_queue<node>q;

    for(int i = 1; i <= n; i++){
        dist[i] =  LLONG_MAX;
        vis[i] = 0;
    }
    q.push({s, 0});
    dist[s] = 0;
    while(q.size()){
        node cd = q.top();
        q.pop();
        if(vis[cd.v])continue;
        vis[cd.v] = 1;
        for(auto j: g[cd.v]){
            int to = j.first;
            ll cost = j.second;
            if(dist[to] > dist[cd.v] + cost){
                dist[to] = dist[cd.v] + cost;
                q.push({to, dist[to]});
            }

        }
    }
}

void bfs(){
    queue<int>q;
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }
    q.push(1);
    vis[1] = 1;
    while(q.size()){
        int cd = q.front();
        q.pop();
        for(int j: G[cd]){
            if(vis[j])continue;
            q.push(j);
            vis[j]++;
        }
    }

}


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
        p[i] = {a, b, c};
    }
    dj(1);
    for(int i = 1; i <= n; i++){
        dist1[i] = dist[i];
    }
    dj(n);
    ll minn = dist1[n];

    for(int i = 1; i <= m; i++){
        ll ans = dist1[p[i].u] + dist[p[i].v] + p[i].w;
        ll ans1 = dist1[p[i].v] + dist[p[i].u] + p[i].w;
        if(ans == minn || ans1 == minn){
            f[i] = 1;
        } 
    }

    for(int i = 1; i <= m; i++){
        if(!f[i]){
            G[p[i].u].push_back(p[i].v);
            G[p[i].v].push_back(p[i].u);
        }
    }
    bfs();
    int ok = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ok = 1;
            break;
        }
    }

    if(ok){
        printf("NO\n");
    }else{
        printf("YES\n");
    }

}