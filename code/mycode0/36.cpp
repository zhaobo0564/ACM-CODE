#include<bits/stdc++.h>
using namespace std;
const int N = 200007;

typedef long long ll;

int n;
ll b[N], a[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &b[i]);
    }
    ll maxn = 0;
    for(int i = 1; i <= n; i++){
        a[i] = maxn + b[i];
        maxn = max(maxn, a[i]);
    }
    for(int i = 1; i <= n; i++){
        printf("%lld ", a[i]);
    }
    puts("");
}