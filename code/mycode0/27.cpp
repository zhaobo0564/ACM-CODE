#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
#define int long long

signed main(){
    ll ans = 4;
    for(int i = 4;i < 100000000;i ++){
        int a = i - 1;
        int b = i;
        int c = i + 1;
        if(b%2==0){
            int p = b + b / 2;
            int s = p*(p-a)*(p-b)*(p - c);
            int s1 = sqrt(s);
            if(s1*s1 == s){
                printf("%lld\n", b);
            }
        }
    }

}