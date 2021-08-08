#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, m, a, b;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if(a > b){
            ll cnt = a - b;
            if(n >= cnt){
                n -= cnt;
                a = b;
            }else{
                a -= cnt;
                n = 0;
            }
        }else{
            ll cnt = b - a;
            if(n >= cnt){
                n -= cnt;
                b = a;
            }else{
                b -= cnt;
                n = 0;
            }
        }
        if(a != b){
            if(m <= b){
                puts("Yes");
            }else{
                puts("No");
            }
        }else{
            if(n > m){
              a -= m;
              n -= m;
             // cout << a << endl;
                a = a + a;
              //  cout << a << " " << n << endl;
                if(a >= n){
                    puts("Yes");
                }else{
                    puts("No");
                }

            }else{
                if(a >= m){
                    puts("Yes");
                }else{
                    puts("No");
                }
            }
        }
        
    }
}