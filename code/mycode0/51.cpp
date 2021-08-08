#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;
ll n, dp[N];
ll mod = 998244353;

ll ksm(ll x, ll c){
    ll base = 1;
    while(c){
        if(c & 1){
            base = base * x % mod;
        }
        c = c / 2;
        x = x * x % mod;
    }
    return base;
}

int  main(){
    // int a = 0, b = 0, c = 0, d = 0;
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         for(int k = 0; k < 10; k++){
    //             for(int z = 0; z < 10; z++){
    //                   if(i != j)a++;
    //                 if(j != k && j != i)a++;
    //                 if(k != j && k != z)a++;
    //                 if(z != k)a++;
    //                 if(i == j && j != k)b++;
    //                 if(i != j && j == k && k!=z)b++;
    //                 if(k != j && k == z)b++;
    //                 if(i == j && j == k && k != z)c++;
    //                 if(i!=j && j == k && k == z)c++;
    //                 if(i == j && j == k && k == z)d++;
                    
    //             }
              
    //         }
    //     }
    // }
    // cout << a << " " << b << " " << c <<" "<<d<< endl;

    scanf("%lld", &n);
    dp[n] = 10;
    ll sum = 10, ans  = 0;
    for(int i = n - 1; i; i--){
        dp[i] = ((ksm(10, n - i + 1) - sum + mod) % mod) * (n - i + 1) % mod;
        dp[i] = (dp[i] +ans ) % mod;
        sum = (sum + dp[i]) % mod;
        ans = (ans + dp[i] * (n - i) % mod) % mod;
    }
    for(int i = 1; i <= n; i++){
        printf("%lld ", dp[i]);
    }
    puts("");
}