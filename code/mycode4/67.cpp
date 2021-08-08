    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    ll t, n, a, b, k;
     
    int main(){
        scanf("%lld %lld %lld %lld %lld", &t, &n, &a, &b, &k);
        a = min(t, a);
        b = min(t, b);
        if(n < k){
            printf("0\n");
        }else{
            ll cnt = min(a, b);
            ll sum = cnt * n;
            ll ans = sum / k;
            ll ans_mod = sum % k;
            if(a > b){
                ll cnt1 = a -  b;
                ll count = (n + 1) / 2;
                if(count + ans_mod >= k){
                    ll sum1 = count * cnt1;
                    ans += sum1 / k;
                    ll ans_mod1 = sum1 % k;
                    ll cn = ans_mod + ans_mod1;
                    ans += cn / k;
                }
                
            }else{
                ll cnt1 = b - a;
                ll count = n / 2;
                if(count+ans_mod >= k){
                    ll sum1 = count * cnt1;
                    ans += sum1 / k;
                    ll ans_mod1 =  sum1 % k;
                    ll cn = ans_mod + ans_mod1;
                    ans += cn / k;
                }
                
            }
            ans = min(ans, t);
            printf("%lld\n", ans);
     
     
        }
    }

Judged Examp