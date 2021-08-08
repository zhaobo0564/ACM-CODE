#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;

int work(ll x){
    ll minn = 10, maxn = 0;
    while(x){
        minn = min(minn, x % 10);
        maxn = max(maxn, x % 10);
        x = x/ 10;
    }

    return minn * maxn;
}

int main(){
    int t;

    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        k--;
        while(k--){
            if(work(n) == 0)break;
            n =n + work(n);
        }
        printf("%lld\n", n);

    }
}