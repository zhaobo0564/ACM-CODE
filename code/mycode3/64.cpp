#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500007];

int main(){
    ll mod = 998244353;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for(int i = 1; i <= n / 2; i++){
        sum += a[i];
        sum = sum % mod;
    }
    for(int i = n / 2 + 1; i <= n; i++){
        sum = (sum % mod * a[i] % mod) % mod;
    }
    printf("%lld\n", sum);
}