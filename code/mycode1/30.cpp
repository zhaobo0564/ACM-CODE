#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[100007];

int main(){
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ans += a[i];
    }
    ll sum = (1ll*n) * 1ll*(n - 1) / 2;
    cout << ans - sum << endl;

}