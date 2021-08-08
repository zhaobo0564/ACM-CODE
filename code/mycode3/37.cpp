#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lowebit(ll x) {
    int cnt = 0;
    while(x){
        if(x & 1)return cnt + 1;
        x = x / 2;
        cnt++;
    }

}

int main(){
    int t ; scanf("%d", &t);
    while(t--){
       // ll n; scanf("%lld", &n);
        ll last = 0;
        ll ans = 0;
        for(int j = 1; j <= 100; j++){
            ans = 0;
            for(int i = 1; i <= j; i++){
        //    cout << lowebit(i) << endl;
            ans += lowebit(i);
        }
        cout << ans <<" " << j <<" " << ans - last << endl;
        last = ans;
        }
        
    }
}