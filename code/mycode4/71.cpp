#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll l, r, a[20], ans = 0;

ll lcm(ll x, ll y){
    return (x * y) / __gcd(x, y);
}

void dfs(int p, int sum, ll value){
    if(value > r)return;
    if(sum % 2 == 0)ans += (r / value) - ((l - 1) / value);
    else ans -= ((r / value) - (l - 1) / value);
    for(int i = p + 1; i <= n; i++){
        dfs(i, sum + 1, lcm(value, a[i]));
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    scanf("%lld %lld", &l, &r);
    dfs(0, 0, 8);
    printf("%lld\n", ans);

}