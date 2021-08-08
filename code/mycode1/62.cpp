#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
int n, m, k;
ll a[N], c[N], w[N], d[N];

pair<ll, ll>g[N];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%lld %lld %lld", &g[i].first, &g[i].second, &w[i]);
    }
    for(int i = 1; i <= k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        c[x]++;
        c[y + 1]--;
    }
    for(int i = 1; i <= m + 1; i++){
        c[i] += c[i -1];
    }
    for(int i = 1; i <= m ; i++){
        if(c[i]){
            d[g[i].first] += w[i]*c[i];
            d[g[i].second + 1] -= w[i]*c[i];
        }
    }
    for(int i = 1; i <= n; i++){
        d[i] += d[i - 1];
        printf("%lld ", d[i] + a[i]);
    }
    puts("");
}