#include<bits/stdc++.h>
using namespace std;
const int N  = 2007;
typedef long long ll;
ll mp[5087][N];
int n;

int main(){
    ll mod = 998244353;
    mp[0][1] = 1;
   for(int i = 1; i <= 5050; i++){
       for(int j = 1; j <=  1011; j++){
           mp[i][j] = mp[i - 1][j];
       }
       for(int j = 1011; j >=1; j--){

           mp[i][j] += mp[i][j - 1];
           mp[i][j] %= mod;
       }
   }

    // for(int  i = 1; i <= 10; i++){
    //     for(int j = 1; j <= 10; j++){
    //         printf("%lld ", mp[i][j]);
    //     }
    //     puts("");
    // }

    scanf("%d", &n);
    while(n--){
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        ll ans = 0;
        if(y > t)ans = 0;
         else ans = mp[t][y + 1]%mod * mp[t-y][x + 1] % mod;
        printf("%lld\n", ans % mod);
    }
·

}