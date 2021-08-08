#include<bits/stdc++.h>
using namespace std;

string s;
int t;
typedef long long ll;
ll mod = 998244353;

ll fpow(ll a, ll x){
    ll base = 1;
    while(x){
        if(x & 1){
            base = base * a % mod;
        }
        a = a * a %mod;
        x = x / 2;
    }
    return base;
}

ll C(int n, int m){
    ll res = 1;
    for(int i = n; i > n - m; i--){
        res = res * i % mod;
    }
    ll res1 = 1;
    for(int i = 1; i <= m; i++){
        res1 = res1 * i % mod;
    }
    res = res * fpow(res1, mod - 2)%mod;
    return res ;
}

int main(){
    scanf("%d",&t);
    while(t--){
        cin>>s;
        int n = s.length();
        int last = -1;
        int ans = 0;
        for(int i =0 ;i<s.length(); i++){
            if(s[i] == 'R'){
                ans = max(ans, i-last);
                last = i;
            }
        }
        ans = max(ans, n-last);
        printf("%d\n",ans);
    }
}