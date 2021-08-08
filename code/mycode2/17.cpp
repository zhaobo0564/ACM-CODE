#include<iostream>
using namespace std;
typedef long long ll;
ll n;
ll mod = 2147493647;

struct matrix{
    ll mp[7][7];
    matrix(){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                mp[i][j] = 0;
            }
        }
    }
};

matrix mul(matrix a, matrix b){
    matrix ans;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < 7; k++){
                ans.mp[i][j] = (ans.mp[i][j] + (a.mp[i][k] % mod * b.mp[k][j] % mod) % mod) % mod;
            }
        }
    }
    return ans;
}   

matrix ksm(matrix cnt, ll n){
   matrix base;
   for(int i =0; i < 7; i++){
       base.mp[i][i] = 1;
   }
   while(n){
       if(n & 1){
           base = mul(base, cnt);
       }
       cnt = mul(cnt, cnt);
       n = n / 2;
   } 
   return base;
}

int main(){
    ll x, y;
    int t; scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &n, &x, &y);
        x = x % mod;
        y = y % mod;
        if(n == 1){
            printf("%lld\n", x);
            continue;
        }
        if(n == 2){
            printf("%lld\n", y);
            continue;
        }
        matrix ans;
        ans.mp[0][0] = 1, ans.mp[0][1] = 2, ans.mp[0][2] = 1;
        ans.mp[1][0] = 1, ans.mp[2][2] = 1, ans.mp[2][3] = 4;
        ans.mp[2][4] = 6, ans.mp[2][5] = 4, ans.mp[2][6] = 1;
        ans.mp[3][3] = 1, ans.mp[3][4] = 3, ans.mp[3][5] = 3;
        ans.mp[3][6] = 1, ans.mp[4][4] = 1, ans.mp[4][5] = 2;
        ans.mp[4][6] = 1, ans.mp[5][5] = 1, ans.mp[6][6] = 1;
        ans.mp[5][6] = 1;
        ans = ksm(ans, n - 2);
        
        matrix res;
        res.mp[0][0] = y;
        res.mp[1][0] = x;
        res.mp[2][0] = 81;
        res.mp[3][0] = 27;
        res.mp[4][0] = 9;
        res.mp[5][0] = 3;
        res.mp[6][0] = 1;
        res = mul(ans, res);
        printf("%lld\n", res.mp[0][0] % mod);

    }

}