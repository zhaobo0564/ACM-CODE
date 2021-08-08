#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+7;
ll a[N], sum[N];
int n, k, t;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &n, &k);
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            ans = ans + a[i] * 1ll * i;
        }
        vector<ll>g;
        for(int i = 1; i <= n; i++){
            if(i > k){
                ll cnt = sum[i - 1] - sum[i - k - 1];
                ll res = a[i] * 1ll * i;
                ll res1 = a[i] * 1ll *(i - k);
                res = res - res1;
                res = cnt - res;
                g.push_back(res);
            }
        }
        sort(g.begin(), g.end());
        ans += g[g.size() - 1];
        printf("%lld\n", ans);
        
    }
}