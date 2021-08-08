#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c, k;

int main(){
    cin >> a >> b >> c >> k;
    ll ans = 0;
    if(k >= a){
        ans += a;
        k -= a;
        if(k >= b){
            k -= b;
            ans -= k;
        }
    }else{
        ans += k;
    }
    cout << ans << endl;
}