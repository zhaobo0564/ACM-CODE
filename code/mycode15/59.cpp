#include<iostream>
using namespace std;
#define ll long long
ll n;
const ll inf=1e9;
ll ksm(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1){
            res=x*res;
            while(res>inf){
                res/=10;
            }
        }
        x=x*x;
        while(x>inf){
            x/=10;
        }
        n/=2;
    }
    return res;
}
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ll m=n;
        while(m>inf){
            m/=10;
        }
        ll res=ksm(m,n);
        ll x=0;
        while(res){
            x=res%10;
            res/=10;
        }
        printf("%lld\n",x);
    }
}