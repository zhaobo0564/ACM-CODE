
#include<stdio.h>

typedef long long ll;

ll a, b, c, d;
ll x, y, x11, y11, x2, y2;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &x11, &y11, &x2, &y2);
        ll cnt1 = x2 - x11;
        ll cnt2 = y2 - y11;
        if(cnt1 == 0 && (a || b)){
            printf("No\n");
            continue;
        }
        if(cnt2 == 0 && (c || d)){
            printf("No\n");
            continue;
        }
        if(a > b){
            a = a - b;
            x = x - a;
            if(c > d){
                c = c - d;
                y -= c;
            }else{
                d = d -c;
                y = y + d;
            }
        }else{
            b = b - a;
            x = x + b;
             if(c > d){
                c = c - d;
                y -= c;
            }else{
                d = d - c;
                y = y + d;
            }
        }

        if(x11 <= x && x2 >= x && y11 <= y && y2 >= y){
                printf("Yes\n");
            }else{
                printf("No\n");
        }
    }
}