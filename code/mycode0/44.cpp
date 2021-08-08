#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int n, sizes[100007];
vector<int> g[100007];

void dfs(int u, int fa){
    sizes[u] = 1;
    for(int i: g[u]){
        if(i == fa){
            continue;
        }
        dfs(i, u);
        sizes[u] += sizes[i];
    }
}

void dfs1(int u, int fa){
    v.push_back(1ll*sizes[u] * 1ll*(n - sizes[u]));
    for(int i: g[u]){
        if(i == fa){
            continue;
        }
        dfs1(i, u);
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0);
    sort(v.begin(), v.end());
    long long c = 1, ans = 0;
    for(int i = v.size() -  1; i >= 0; i--){
        ans += v[i] * c;
        c++;
    }
    printf("%lld\n", ans);
}