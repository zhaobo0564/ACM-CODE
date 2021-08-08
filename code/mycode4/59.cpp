#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, pos[N];

struct node{
    int u, v;
    bool operator <(const node a)const{
        return v > a.v;
    }
};

vector<pair<int, int> >g[N];
priority_queue<node>q;
int dist[N], vis[N], fa[N];

void dij(){
    q.push({1, 0});
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
        dist[i] = 1e8;
        fa[i] = 0;
    }
    dist[1] = 0;

    while(q.size()){
        node cd = q.top();
        q.pop();
        if(vis[cd.u])continue;
        for(auto it: g[cd.u]){
            int to = it.first;
            int cost = it.second;
            if(dist[to] > dist[cd.u] + cost){
                dist[to] = dist[cd.u] + cost;
                q.push({to, dist[to]});
                fa[to] = cd.u;
            }
        }
    }
}
vector<int>v;

int main(){
    while(~scanf("%d", &n)){
        v.clear();

        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            g[i].clear();
            pos[a[i]] = 0;
        }
        for(int i = 1; i < n; i++){
            g[i].push_back({i + 1, 1});
        }
        for(int i = 1; i <= n; i++){
            if(pos[a[i]]){
                g[pos[a[i]]].push_back({i, 0});
            }
            pos[a[i]] = i;
        }
        dij();
        int x = n;

        while(x){
            v.push_back(a[x]);
            x = fa[x];
        }
        v.push_back(-1);
        reverse(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[i - 1])continue;
            printf("%d ", v[i]);
        }
        puts("");

    }
}