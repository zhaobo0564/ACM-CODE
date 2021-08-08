#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll ksm(ll a, ll mod){
    
}
 
int main()
{
    ll a,b,c,x,y,d;
    ll t; scanf("%lld", &t);
    while(t--){
        cin>>a>>b;
        d=ex_gcd(a,b,x,y);
        c = __gcd(a, b);
        if(c%d!=0) cout<<"-1"<<endl;
        else{
            ll ans = c/d*x+(b/d*c)/(d*c/d);
            while(ans < 0) ans += b;
            cout << ans << endl;
        }
    }
     
    return 0;
}