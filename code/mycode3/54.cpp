#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
vector<pair<int, int> >g[N];

ll sum, mod, cnt;
int vis[N];

void dfs(int u, int fa){
    vis[u] = 1;
    for(auto it: g[u]){
        int to = it.first;
        if(to == fa)continue;
        cnt++;
        dfs(to, u);
    }
}

ll ksm(ll a, ll x){
    ll base = 1;
    while(x){
        if(x & 1) base = base * a % mod;
        x = x / 2;
        a = a * a % mod;
    }
    return base;
}

int main(){
    ll n, k;
    mod = 1e9 + 7;
    scanf("%lld %lld", &n, &k);
    sum = 1;
    sum = ksm(n, k);
    //cout << sum << endl;

    for(int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if(w == 1)continue;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cnt = 1;
        if(vis[i])continue;
        dfs(i, 0);
        if(cnt == 1) continue;
        ans += ksm(cnt, k);
        ans = ans % mod;
        ans = (ans - cnt + mod) % mod; 
    }
    ans = ans + n;
    ans = (sum - ans  + mod) % mod;
  
    printf("%lld\n", ans);

}