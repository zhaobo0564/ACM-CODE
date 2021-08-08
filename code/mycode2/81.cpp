#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll n, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        ll minn = LLONG_MAX;
        for(ll i = 1; i <= k; i++){
            if(i * i > n)break;
            if(n % i == 0){
                minn = min(minn, n / i);
                if(n / i <= k){
                    minn = min(minn, i);
                }
            }
        }
        printf("%lld\n", minn);
    }
}
