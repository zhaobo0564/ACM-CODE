#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
int n;
vector<ll>g;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 2; i <= n; i++){
        g.push_back(a[i] - a[i - 1]);
    }
    ll gcd = abs(g[0]);
    for(int i = 1; i < g.size(); i++){
        gcd = __gcd(gcd, abs(g[i]));
    }
   
    if(a[1] > 0){
        ll cnt = gcd - a[1] % gcd;
        if((a[1] % gcd) == 0)cnt = 0;
        printf("%lld %lld\n", gcd, cnt);
    }else{
        a[1] = -a[1];
        ll cnt = a[1] % gcd;
        printf("%lld %lld\n", gcd, cnt);
    }
    

}