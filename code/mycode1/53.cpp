#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;

typedef long long ll;

vector<pair<ll, ll> >g[N];


struct node{
    int v;
    long long w;
    bool operator <(const node a)const{
        return w > a.w;
    }

};

int n, m, f[N], s, t;
ll dist[N], vis[N], dist1[N], top;

vector<int>v[1007];
int a[N], b[N], c[N];

int cnt[N];

void dj(int s){
    priority_queue<node>q;

    for(int i = 1; i <= top; i++){
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


int main(){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    top = n + 1;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        int last = 0;
        for(int j = 1; j <= c[i]; j++){
            int x; scanf("%d", &x);
            if(last){
                g[top].push_back({top - 1, b[i]});
                g[top - 1].push_back({top, b[i]});
            }
            g[top].push_back({x, a[i]});
            g[x].push_back({top, 0});
            top++;
            last = x;
        }
    }
    dj(s);
    if(dist[t] == LLONG_MAX){
        puts("-1");
    }else{
        printf("%lld\n", dist[t]);
    } 
}
