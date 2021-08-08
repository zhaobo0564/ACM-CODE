#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k;

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        if(n % 2 == 0){
            printf("%lld\n", n + 2 * k);
        }else{
            int ans = 0;
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0){
                    ans = i;
                    break;
                }
            }
            if(ans == 0)ans = n;
            printf("%lld\n",n + ans + (k - 1) * 2 );
        }
    }
}