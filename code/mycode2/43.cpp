#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000007;
vector<ll> g[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        g[i].push_back(0);
        ll sum = 0;
        for(int j = 1; j <= m; j++){
            ll x; scanf("%lld", &x);
            sum += x;
            g[i].push_back(x);
        }
        g[i].push_back(sum);
    }
    g[n + 1].push_back(0);
    for(int i = 1; i <= m; i++){
        ll sum = 0;
        for(int j = 1; j <= n; j++){
            sum += g[j][i];
        }
        g[n + 1].push_back(sum);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll ans = g[i][m + 1] + g[n + 1][j];
            printf("%lld ", ans - g[i][j]);
        }
        puts("");
    }
}