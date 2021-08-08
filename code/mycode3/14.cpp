#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 214514;
const int inf = 0x3f3f3f3f;
struct line{
    int v;
    ll k, b;
 
};
 
vector<line> g[N];
ll dist[N];
int n, m, h, vis[N];
 
struct node{
    int v;
    ll cost;
 
    bool operator <(const node n)const{
        return cost > n.cost;
    } 
};
priority_queue<node>q;
 
ll dij(ll x){
    for(int i = 1; i <= n; i++){
        dist[i] = 1e18;
        vis[i] = 0;
    }
    
    q.push({1, 0});
    dist[1] = 0;
    while(q.size()){
        node cd = q.top();
        q.pop();
        if(vis[cd.v])continue;
        vis[cd.v] = 1;
        for(line it: g[cd.v]){
            int to = it.v;
            ll cost = it.k * x + it.b;
            if(dist[to] > dist[cd.v] + cost){
                dist[to] = dist[cd.v] + cost;
                q.push({to, dist[to]});
            }
        }
    }
    return dist[n];
}
 
ll work(int l, int r){
    if(r - l <= 10){
        ll ans = 0;
        for(int i = l; i <= r; i++){
            ans = max(ans, dij(1ll * i));
        }
        return ans;
    }
    int midl = (l + r) / 2;
    int midr = (midl + r) / 2;
    ll maxl = dij(1ll * midl);
    ll maxr = dij(1ll * midr);
    if(maxl >= maxr){
        return work(l, midr);
    }else{
        return work(midl, r);
    }
 
}
 
int main(){
    scanf("%d %d %d", &n, &m, &h);
    for(int i = 1; i <= m; i++){
        int u, v;
        ll k, b;
        scanf("%d %d %lld %lld", &u, &v, &k, &b);
        //if(u == v)continue;
        g[u].push_back({v, k, b});
      //  g[v].push_back({u, k, b});
    }
    printf("%lld\n", work(0, h));
 
}