#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll ex_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0) {x=1;y=0;return a;}
    ll d=ex_gcd(b,a%b,x,y);//求出a,b的最大公约数
    ll tmp=x;x=y;y=tmp-a/b*y;
    return d;
}


int main(){
    ll  a, b, c;
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