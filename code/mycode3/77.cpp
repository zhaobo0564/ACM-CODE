#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll>g;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        ll x; scanf("%lld", &x);
        g.push_back(x);
    }
    sort(g.begin(), g.end());
    g.push_back(LLONG_MAX);
    int ans = 0, maxn = 0;
    for(int i = 0; i < g.size() - 1; i++){
        int p = upper_bound(g.begin(), g.end(), g[i] + 5) - g.begin();
  
        ans = max(ans, p - i );
    }
    printf("%d\n", ans);
}