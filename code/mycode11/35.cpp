#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N=170000007;
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


ll ksm(ll x, ll y) {
    x = x % mod;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x % mod * x % mod % mod;
        y = y / 2;
    }
    return base % mod;
}


int main() {
    Prime();
    ll n;
    cin >> n;
    ll ans = 1;
    ll base = 2;
    for (int i = 1; i <= 30; i++) {
        if (base * 3 > n) {
            ans = (ans % mod * ksm(2, i - 1)) % mod;
            break;
        }
        base = base * 2;
    }
    for (int i = 2; i < top; i++) {
        base = 1;

        for (int j = 1; j <= 30; j++) {
            base = base * prime[i];
            if (base * 2 > n) {
                ans = (ans % mod * ksm(prime[i], j - 1)) % mod;
                break;
            }
        }
    }
    if (ans == 1) {
        puts("empty");
        return 0;
    }
    cout << ans << endl;


}