#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
ll a[N], sum[N];
int n;

map<ll, ll>vis;


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];89
        vis[sum[i]] = -1;
    }
    ll ans = 0;
    ll maxn = 0;
    ll last = 0;
    vis[0] = 0;
    for(int i = 1; i <= n; i++){
        if(vis[sum[i]] != -1){
            ll r = vis[sum[i]] + 1;
            if(r > last)last = r;
        }
        ans += i -last;

     //   last[sum[i]] = vis[sum[i]];
        vis[sum[i]] = i;
    }
   // ll sum = ((1ll*n + 1) * (1ll * n)) / 2;
    printf("%lld\n",  ans);

}