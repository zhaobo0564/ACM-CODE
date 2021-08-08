#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1007;
int n;

struct node{
    ll x, y, r;
    int falg;
    ll w1, w2;

}p[N];

ll dist(node x, node y){
    return (x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y);
}

vector<int>g[N];
int vis[N];

void dfs(int u, int fa){
    vis[u] = 1;
    for(int j : g[u]){
        if(j == fa)continue;
        p[j].w1 = p[u].w1 * p[u].r;
        p[j].w2 = p[u].w2 * p[j].r;
        if(p[j].w1 ==0 || p[j].w2 == 0)continue;
        ll gg = __gcd(p[j].w1, p[j].w2);
        if(gg == 0)continue;
        p[j].w1 /= gg;
        p[j].w2 /= gg;
        p[j].falg = -p[u].falg;
        if(vis[j])continue;
        dfs(j, u);
    }
}

int main(){
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            scanf("%lld %lld %lld", &p[i].x, &p[i].y, &p[i].r);
            p[i].falg = 0;
            p[i].w1 = p[i].w2 = 0;
        }
        p[1].falg = 1;
        p[1].w1 = p[1].w2 = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ll r = p[i].r + p[j].r;
                if(r*r == dist(p[i], p[j])){
                   g[i].push_back(j);
                   g[j].push_back(i);
                }
            }
        }
        dfs(1, 0);
        for(int i = 1; i <= n; i++){
            if(p[i].falg == 1){
                if(p[i].w1 == p[i].w2){
                    printf("1 clockwise\n");
                }else if(p[i].w2 == 1){
                    printf("%lld clockwise\n", p[i].w1);
                }else{
                    printf("%lld/%lld clockwise\n", p[i].w1 , p[i].w2);
                }
            }else if(p[i].falg == 0){
                puts("not moving");
            }else if(p[i].falg == -1){
                if(p[i].w1 == p[i].w2){
                    printf("1 counterclockwise\n");
                }else if(p[i].w2 == 1){
                    printf("%lld counterclockwise\n", p[i].w1);
                }else{
                    printf("%lld/%lld counterclockwise\n", p[i].w1 , p[i].w2);
                }
            }
        }

    }
}
/*1
5
0 0 6
6 8 4
-9 0 3
6 16 4
0 -11 4*/