#include<bits/stdc++.h>
using namespace std;

long long a, b, c, d, p, m;

int main(){
    int t; scanf("%d", &t);
    int ca = 0;
    while(t--){
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &p, &m);
        a = a + p - m + p; 
        b = b + p - m + p;
        c = c + a;
        d = d + a;
        long long cnt = (c - 1) / p;
        long long cnt1 = d / p;
        long long ans = cnt1 - cnt;
        cout << "ans = " << ans << endl;
        ans = ans * (b - a + 1);
        //cout << c << endl;
        ans = ans - c % p - 1;
        long long res = (b - a + 1) * (d - c + 1);
        long long  g = __gcd(ans, res);
        printf("Case #%d: ", ++ca);
        printf("%lld/%lld\n", ans / g, res / g);

    }
}