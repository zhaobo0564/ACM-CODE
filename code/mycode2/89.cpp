#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;

struct node{
    ll a, b, c,d;
};

vector<node>g;
ll res = 0;
int vis[20];

void dfs(int p, int value){
    if(p == n){
        ll ans = 0, ans1 = 0;
        int x = value;
        int cnt = 0;
        while(x){
            if(x & 1){
                vis[cnt] = 1;
            }
            cnt++;
            x = x / 2;
        }
        for(int i = 0; i < n; i++){
            if(vis[i]){
                ans += g[i].a;
                if(ans1 <= g[i].b){
                    ans1 = 0;
                }else{
                    ans1 -= g[i].b;
                }
            }else{
                ans1 += g[i].c;
                if(ans <= g[i].d){
                    ans = 0;
                }else{
                    ans -= g[i].d;
                }
            }
        }
     

        for(int i = 0; i <= n + 1; i++)vis[i] = 0;
       // cout << "ans =" << ans << " ans1 = " << ans1 << " " << ans * ans1 << endl;
        res = max(res, ans1 * ans);
        return;
    }
    dfs(p + 1, value | (1 << (p)));
    dfs(p + 1, value);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        g.push_back({a, b, c, d});
    }
    dfs(0, 0);
    printf("%lld\n", res);
}