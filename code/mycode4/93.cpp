#include<bits/stdc++.h>

using namespace std;

int n;
long long a[200007];

long long mod = 1e9 + 7;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 2 * n + 1);
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        //cout << a[i] << " " << a[2 *n - i + 1] << endl;
        ans = (ans % mod * (a[i]  + a[2 * n - i + 1] ) % mod) % mod;
    }
    printf("%lld\n", ans);
}