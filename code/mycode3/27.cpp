#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[200];

int main(){
    scanf("%d", &n);
    ll minn = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[n + i] = a[i];
    }
    for(int i = 1; i <= n; i++){
        ll ans = 0;
        for(int j = i + 1; j < n + i - 1; j++){
            ans += a[j] * a[j + 1];
        }
        minn = min(ans * a[i], minn);
        
    }
    printf("%lld\n", minn);
}