#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
typedef long long ll;

ll cnt[N];

struct node{
    ll v;
    char s;
}p[N];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n;
        ll a = 0, b = 0, sum = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld  %c", &p[i].v, &p[i].s);
            if(p[i].s == 'B'){
                b += p[i].v;
            }else{
                a += p[i].v;
            }
        }
        sum = a + b;
        if(a == 0 || b == 0){
            printf("%lld\n", sum);
        }else{
            ll res = 0;
            ll g = __gcd(a, b);
            a /= g;
            b /= g;
        
            ll all_a = 0, all_b = 0;
            for(int i = 1; i <= n; i++){
              if(p[i].s == 'B'){
                  all_b += p[i].v;
                  if(all_a && all_a % a == 0){
                      if(all_b / b >= all_a / a && (all_b - p[i].v) / b < all_a/a){
                          res++;
                      }
                  }
                  
              }else{
                  all_a += p[i].v;
                  if(all_b && all_b % b == 0){
                      if((all_a - p[i].v) / a < all_b / b && all_a / a >= all_b / b){
                          res++;
                      }
                  }
              }
            
        }
        printf("%lld\n", res);

    }
}
}

