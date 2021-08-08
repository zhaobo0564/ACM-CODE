#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, a, b, k, ans;

int main(){
    scanf("%lld %lld %lld %lld %lld", &t, &n, &a, &b, &k);
    a = min(t, a);
    b = min(t, b);
    if(n < k){
        printf("0\n");
    }else{
        ll na = (n + 1) / 2;
        ll nb = (n - na);
        ans = (na / k) * a;
        na = na % k;
        ans += (nb / k) * b;
        nb = nb % k;
        ll cha = (k - na) * a;
        ll cn = 0;
        ll sumb = nb * b;
        if(sumb > cha)

      
        

       

        printf("%lld\n", ans);
    }
    
}