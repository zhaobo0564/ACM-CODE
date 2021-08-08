#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N=2e6+7;
int prime[N],vis[N],top=1;
 
void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
 
        }
    }
}
 
ll a, b;
 
ll exgcd(ll a, ll b, ll &x, ll &y)  {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int ca[N];

int main() {
    int t; scanf("%d", &t);
    Prime();
    for (int i = 1; i < top; i++) {
        if (prime[i] > 2e6)break;
        ca[prime[i]] = 1;
    }
    while (t--) {
        scanf("%lld %lld", &b, &a);
        ll g = __gcd(a, b);
        if (g != 1) {
            a = a / g;
            b = b / g;
            printf("%lld %lld %lld %lld\n", b + 1, a, 1ll*1, a);
        } else {
            if (a == 1) {
                printf("-1 -1 -1 -1\n");
            } else {
                int f = 1;
                if (ca[a]) f = 0;
                if (f == 0) {
                    printf("-1 -1 -1 -1\n");
                } else {
                    ll d = 1;
                    ll f = 1;
                    ll pos = 2;
                    for (long long i = 2; i * i <= a; i++) {
                        if (a % i == 0) {
                            while(a % i == 0) d = d * i, a = a / i;
                            pos = i;
                            break;
                        }
                        
                    }
                    if (a == 1) {
                        printf("-1 -1 -1 -1\n");
                    } else {
                        for (ll i = pos; i * i <= a; i++) {
                            if (a % i == 0) {
                                while ( a % i == 0) f = f * i, a = a/ i;
                            }
                        }
                        if (a > 1) f = f * a;
                    //    cout << "d " << d <<" f = " << f << endl;
                        ll x, y;
                        exgcd(d, f, x, y);
                        ll c = x * b;
                        ll e = y * b;
                        if (c < 0) {
                            printf("%lld %lld %lld %lld\n", e, d, -c, f);
                        } else {
                            printf("%lld %lld %lld %lld\n", c, f, -e, d);
                        }
 
                    }
                }
            }
        }
    }
}