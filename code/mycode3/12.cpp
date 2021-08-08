#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 114524;

struct line{
    ll k, b;
}a[N];
ll dist[N], vis[N];

vector<pair<int, int> > g[N];
int n, m, h;

struct node{
    int v;
    ll cost;
    bool operator <(const node x)const{
        return cost > x.cost;
    }
};

void dij(ll x){
    priority_queue<node>q;
    q.push({1, 0});
    for(int i = 1; i <= n + 1; i++){
        dist[i] = 3e18;
        vis[i] = 0;
    }
    dist[1] = 0;
    while(q.size()){
        node cd = q.top();
        q.pop();
        if(vis[cd.v]) continue;
        vis[cd.v] = 1;
        for(auto it: g[cd.v]){
            int to = it.first;
            ll cost = 1ll*a[it.second].k * x + 1ll * a[it.second].b;
            //cout <<"cost " << cost << endl;
            if(dist[to] > dist[cd.v] + cost){
                dist[to] = dist[cd.v] + cost;
                q.push({to, dist[to]});
            }
        }
    }
    //cout <<"a " << dist[n] << endl; 
}

ll work(ll l, ll r){
    if(r - l <= 10){
        ll ans = 0;
        for(ll i = l; i <= r; i++){
            dij(i);
            ans = max(ans, dist[n]);
        }
        return ans;
    }
    ll mid = (l + r) / 2;
    dij(mid);
    ll max1 = dist[n];
    ll mid1 = (r + mid) / 2;
    dij(mid1);
    ll max2 = dist[n];
    if(max1 >= max2){
        return work(l, mid1);
    }else{
        return work(mid, r);
    }

}

int main(){
    scanf("%d %d %d", &n, &m, &h);
    for(int i = 1; i <= m; i++){
        int u, v;
        ll k, b;
        scanf("%d %d %lld %lld", &u, &v, &k, &b);
        if(u == v) continue;
        g[u].push_back({v, i});
       // g[v].push_back({u, i});
        a[i].b = b;
        a[i].k = k;
    }
    ll l = 0, r = h;
    printf("%lld\n", work(l, r));
  
    
    
}

